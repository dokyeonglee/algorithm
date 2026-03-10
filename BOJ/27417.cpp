#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int init_digit_sum;

    cout << "query 0" << endl;
    cin >> init_digit_sum;

    ll answer = 0;
    ll p = 1;
    for (int i = 0; i < 18; ++i) {
        int digit = 0;
        int left = 0;
        int right = 9;
        while (left <= right) {
            int mid = (left + right) / 2;
            int x;
            cout << "query " << p * mid << endl;
            cin >> x;

            if (init_digit_sum + mid == x) {
                digit = 9 - mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        answer += digit * p;
        p *= 10;
    }

    cout << "answer " << answer << endl;

    return 0;
}