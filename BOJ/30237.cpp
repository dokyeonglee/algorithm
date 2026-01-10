#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<ll> sets(n);
        ll union_set = 0;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;

            for (int j = 0; j < x; ++j) {
                int a;
                cin >> a;

                sets[i] |= (1ll << a);
            }

            union_set |= sets[i];
        }

        int answer = 0;

        for (int i = 1; i <= 50; ++i) {
            const ll bit = (1ll << i);
            if (union_set & bit) {
                ll temp = 0;
                for (const ll s : sets) {
                    if ((s & bit) == 0) {
                        temp |= s;
                    }
                }
                answer = max(answer, __builtin_popcountll(temp));
            }
        }

        cout << answer << '\n';
    }

    return 0;
}