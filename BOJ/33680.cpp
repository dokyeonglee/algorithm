#include <iostream>
#include <vector>

using namespace std;

long long pow(long long a, long long n, const long long mod){
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

    const long long mod = 1e9 + 7;

    int t;
    cin >> t;

    while(t--){
        long long p, n;
        cin >> p >> n;
        cout << (pow(p, n, mod) - 1) * pow(p - 1, mod - 2, mod) % mod << "\n";
    }

    return 0;

}