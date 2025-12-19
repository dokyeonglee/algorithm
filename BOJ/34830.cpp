#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long answer = 1ll * n * (n - 1) / 2;

    if (n % 2 == 0) {
        answer += n / 2 - 1;
    }

    cout << answer << '\n';

    return 0;
}