#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

long long pow(long long a, long long n){
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

    int n, m;
    cin >> n >> m;

    m = min(m, n - m);

    long long x = 1;
    long long y = 1;

    for(int i = 1; i <= m; i++){
        x = (n - i + 1) * x % mod;
        y = i * y % mod;
    }

    cout << x * pow(y, mod - 2) % mod;

    return 0;

}