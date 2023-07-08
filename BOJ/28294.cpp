#include <iostream>
#include <vector>

using namespace std;

long long pow(long long a, long long n, int mod){
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

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, a;
    cin >> n >> a;

    int mod = 1e9 + 7;

    long long na = pow(n, a, mod);

    long long answer = n * (n - 2) % mod;
    answer = answer * (na - (pow(n - 1, a, mod))) % mod;
    answer = (answer + na * n) % mod;

    cout << answer;

    return 0;
}