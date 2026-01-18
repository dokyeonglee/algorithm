#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    double answer = 1;
    for (int i = n - 1; i >= 1; --i) {
        answer += 1.0 * n / i;
    }

    cout << fixed;
    cout.precision(10);
    cout << answer << '\n';

    return 0;
}