#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string a(n, '!');
    string b(a);

    b[n - 2] = a[n - 2] + 1;
    b[n - 1] = (a[n - 1] - 31);

    cout << a << "\n";
    cout << b;

    return 0;
}