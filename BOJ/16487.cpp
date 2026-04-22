#include <iostream>

using namespace std;

int main() {
    int a, b, c, m;
    cin >> a >> b >> c >> m;

    double cos_t = (a * a + b * b - c * c) / (2.0 * a * b);

    cout << fixed;
    cout.precision(10);
    cout << (a * a + m * m - cos_t * 2 * a * m);

    return 0;
}