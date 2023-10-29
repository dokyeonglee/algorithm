#include <iostream>
#include <vector>

using namespace std;

long long pow(long long a, long long n, long long mod){
    if(n == 0){
        return 1;
    }
    auto result = pow(a, n / 2, mod);
    result = result * result % mod;
    if(n % 2){
        result = result * a % mod;
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long a, b;
    cin >> a >> b;

    const int mod = 1e9 + 7;

    if(a == 1){
        cout << b % mod;
    }else{
        cout << (pow(a, b, mod) - 1) * pow(a - 1, mod - 2, mod) % mod;
    }

    return 0;
}