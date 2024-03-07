#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    const int mod = 1e9 + 7;
    const int two_mod_inv = 5e8 + 4;

    long long v = n;
    long long e = n - 1;

    for(int i = 0; i < k; i++){
        v = v * e % mod * two_mod_inv % mod;
        e = 2 * (e - 1) % mod;
    }

    cout << v;

    return 0;
}