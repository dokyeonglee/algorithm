#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < 7; ++i) {
        string str(n, 'A');
        for (int j = (1 << i); j < n; j += (2 << i)) {
            for (int k = 0; k < (1 << i) && j + k < n; ++k) {
                str[j + k] = 'B';
            }
        }
        if (n <= (1 << i)) {
            str.back() = 'B';
        }
        cout << str << '\n';
    }

    return 0;
}