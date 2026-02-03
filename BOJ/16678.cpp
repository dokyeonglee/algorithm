#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> cnt(100001);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
    }

    int t = 1;
    int idx = 1;
    long long hackers = 0;

    while (idx < cnt.size()) {
        if (cnt[idx] == 0 || idx < t) {
            ++idx;
        } else {
            hackers += idx - t++;
            --cnt[idx];
        }
    }

    cout << hackers;

    return 0;
}