#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> boxes(n);
    for (int& box : boxes) {
        cin >> box;
    }

    sort(boxes.begin(), boxes.end());

    int answer = n;
    int left = 0;
    int right = (n + 1) / 2;
    while (right < n) {
        if (2 * boxes[left] <= boxes[right]) {
            --answer;
            ++left;
        }
        ++right;
    }

    cout << answer;

    return 0;
}