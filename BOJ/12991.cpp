#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll count_elements_leq(const vector<int>& a, const vector<int>& b, const ll x) {
    ll cnt = 0;
    int idx = b.size();
    for (const ll ai : a) {
        while (idx > 0 && ai * b[idx - 1] > x) {
            --idx;
        }
        if (idx == 0) {
            return cnt;
        }
        cnt += idx;
    }
    return cnt;
}

ll find_kth_element(vector<int>& a, vector<int>& b, const ll k) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll left = 1ll * a.front() * b.front();
    ll right = 1ll * a.back() * b.back();
    ll kth_element = 0;

    while (left <= right) {
        ll mid = (left + right) / 2;
        if (count_elements_leq(a, b, mid) >= k) {
            kth_element = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return kth_element;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> b(n);

    for (auto& ai : a) {
        cin >> ai;
    }

    for (auto& bi : b) {
        cin >> bi;
    }

    cout << find_kth_element(a, b, k) << '\n';

    return 0;
}