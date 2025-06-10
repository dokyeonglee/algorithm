#include <iostream>
#include <vector>

using namespace std;

void make_base(int n) {
    if (n % 2) {
        cout << "6 * 7\n3 + 42\n5 * 45\n2 * 4\n1 + 8\n225 * 9\n";
    } else {
        cout << "8 - 4\n6 * 7\n3 + 42\n5 * 45\n2 * 4\n1 + 8\n225 * 9\n";
    }
}

void remove_others(int n) {
    int base_number = 8 - n % 2;
    for (int i = n; i > base_number; i -= 2) {
        cout << i << " - " << i - 1 << '\n';
        cout << "2025 * 1\n";
    }
}

void make_2025(const int n) {
    if (n < 7) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        make_base(n);
        remove_others(n);
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    make_2025(n);

    return 0;
}