#include <iostream>
#include <vector>

using namespace std;

long long pow(long long a, long long n, long long mod){
    long long result = 1;
    while(n > 0){
        if(n & 1){
            result = result * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const int mod = 1e9 + 7;

    int n, k;
    cin >> n >> k;

    long long n_factorial = 1;
    long long x = 1;

    for(int i = 2; i <= n; i++){
        n_factorial = i * n_factorial % mod;
        x = (i + k - 1) / k * x % mod;
    }

    cout << n_factorial * pow(x, mod - 2, mod) % mod;

    return 0;
}