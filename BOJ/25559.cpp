#include <iostream>
#include <vector>

using namespace std;

void print_pass_order(int n) {
    if (n == 1) {
        cout << "1\n";
    } else if (n % 2 == 1) {
        cout << "-1\n";
    } else {
        for (int i = 0; i < n; i += 2) {
            cout << n - i << ' ' << i + 1 << ' ';
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    print_pass_order(n);

    return 0;
}