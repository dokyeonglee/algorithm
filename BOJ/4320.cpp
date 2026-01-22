#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        long long n;
        cin >> n;

        if (n == 0) {
            break;
        }

        int answer = 1;

        if (abs(n) != 1) {
            long long temp = abs(n);
            int sqrtn = sqrtl(temp);
            for (int i = 2; i <= sqrtn; ++i) {
                long long a = 1;
                for (int j = 1; j <= 31; ++j) {
                    a *= i;
                    if (a > temp) {
                        break;
                    }
                    if (a == temp) {
                        answer = j;
                        break;
                    }
                }
                if (answer > 1) {
                    break;
                }
            }

            if (n < 0) {
                answer /= (answer & -answer);
            }
        }
        cout << answer << '\n';
    }

    return 0;
}