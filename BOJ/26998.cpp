#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w;
    cin >> n >> w;

    vector<pair<int, int>> arr(n);
    for (auto& [x, y] : arr) {
        cin >> x >> y;
    }

    int answer = 0;
    stack<int> s;
    for (auto& [x, y] : arr) {
        while (!s.empty() && s.top() > y) {
            ++answer;
            s.pop();
        }
        if (y && (s.empty() || s.top() != y)) {
            s.push(y);
        }
    }

    answer += s.size();
    cout << answer;

    return 0;
}