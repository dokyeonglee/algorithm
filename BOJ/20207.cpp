#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> schedule_count(367);
    for (int i = 0; i < n; ++i) {
        int s, e;
        cin >> s >> e;

        ++schedule_count[s];
        --schedule_count[e + 1];
    }

    for (int i = 1; i <= 366; ++i) {
        schedule_count[i] += schedule_count[i - 1];
    }

    int height = 0;
    int width = 0;
    int answer = 0;

    for (int i = 1; i <= 366; ++i) {
        if (schedule_count[i] == 0) {
            answer += width * height;
            height = 0;
            width = 0;
        } else {
            height = max(height, schedule_count[i]);
            ++width;
        }
    }

    cout << answer << '\n';

    return 0;
}