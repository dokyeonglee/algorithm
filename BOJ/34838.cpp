#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    ll nC3 = n * (n - 1) * (n - 2) / 6;
    ll triangles;

    if (n % 3 == 0) {
        triangles = (nC3 - n / 3) / n + 1;
    } else {
        triangles = nC3 / n;
    }

    cout << triangles << '\n';

    return 0;
}