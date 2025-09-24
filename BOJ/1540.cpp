#include <iostream>
#include <cmath>

using namespace std;

int count_squares(const int n) {
    const int side = sqrt(n);
    const int remainder = n - side * side;

    int squares = (side - 1) * side * (2 * side - 1) / 6;
    if (remainder <= side) {
        squares += (remainder - 1) * remainder / 2;
    } else {
        squares += (side - 1) * side / 2;
        squares += (remainder - side - 1) * (remainder - side) / 2;
    }

    return squares;
}

int main() {
    int n;
    cin >> n;

    cout << count_squares(n) << '\n';

    return 0;
}