#include <iostream>
#include <vector>

using namespace std;

long long pow(long long a, long long n, long long mod){
    long long result = 1;
    while(n){
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

    long long n, m;
    cin >> n >> m;

    const int mod = 1e9 + 7;

    if((1 << n) < m){
        cout << 1;
    }else{
        long long temp = pow(2, n * m, mod);
        long long temp2 = pow(temp, mod - 2, mod);
        int x = (1 << n);
        long long answer = 1;
        for(int i = 0; i < m; i++){
            answer = answer * (x - i) % mod;
        }
        answer = (temp - answer + mod) * temp2 % mod;
        cout << answer;
    }

    return 0;
}