#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int& x : a) {
        cin >> x;
    }

    for (int& x : b) {
        cin >> x;
    }

    vector<pair<int, int>> v;
    v.emplace_back(a[0], b[0]);
    for (int i = 1; i < n; ++i) {
        while (!v.empty() && v.back().first > a[i] && v.back().second > b[i]) {
            v.pop_back();
        }
        if (v.empty() || v.back().first > a[i] || v.back().second > b[i]) {
            v.emplace_back(a[i], b[i]);
        }
    }

    cout << v.size() << '\n';

    return 0;
}