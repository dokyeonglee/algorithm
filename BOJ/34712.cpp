#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr int MAX_X = 100000;

ll ask(const int t) {
    cout << "? " << t << endl;
    ll sum;
    cin >> sum;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int left = 1;
    int right = MAX_X;
    int answer = MAX_X;

    const ll f = ask(right);
    if (f) {
        while (left <= right) {
            const int mid = (left + right) / 2;
            ll sum = ask(mid);
            if (f - sum >= 1ll * n * (MAX_X - mid)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }

    cout << "! " << answer << endl;

    return 0;
}