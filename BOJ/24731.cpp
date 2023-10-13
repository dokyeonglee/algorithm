#include <iostream>
#include <vector>

using namespace std;

long long pow(long long a, long long n, long long mod){    

    if(n == 0){
        return 1;
    }

    long long result = pow(a, n / 2, mod);
    result = result * result % mod;

    if(n % 2){
        result = result * a % mod;
    }

    return result;

}


int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    const int mod = 1e6 + 3;
    
    long long answer = pow(2, n, mod) - 1;

    answer = (answer * (answer - 1)) % mod;
    answer = (answer * pow(6, mod - 2, mod)) % mod;

    cout << answer;

    return 0;

}