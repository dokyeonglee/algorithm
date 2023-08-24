#include <iostream>
#include <vector>

using namespace std;

long long pow(long long a, long long n, long long mod){
    if(n == 0){
        return 1;
    }
    long long result = pow(a, n / 2, mod);
    result = result * result % mod;
    if(n % 2 == 1){
        result = result * a % mod;
    }
    return result;
}

long long geometric_progression(long long a, long long n, long long r, long long mod){
    if(n == 1){
        return a % mod;
    }
    long long result = geometric_progression(a, n / 2, r, mod);
    result = (result + result * pow(r, n / 2, mod)) % mod;
    if(n % 2 == 1){
        result = (a + result * r) % mod;
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long a, r, n, mod;
    cin >> a >> r >> n >> mod;

    cout << geometric_progression(a, n, r, mod);

    return 0;
}