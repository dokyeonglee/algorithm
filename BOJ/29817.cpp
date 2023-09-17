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

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long p, c, k;
    cin >> p >> c >> k;

    const int mod = 1e9 + 7;

    vector<long long> arr(p);
    for(int i = 0; i < p; i++){
        cin >> arr[i];
        arr[i] = (arr[i] + mod) % mod;
    }

    vector<long long> brr(p + 1);
    for(int i = 1; i < p; i++){
        brr[i] = arr[i] - arr[i - 1];
    }

    long long t = c;

    for(int i = 1; i < p; i++){
        brr[i] = (brr[i] + mod) % mod;
    }

    for(int i = 1; i < p; i++){
        brr[p] = ((brr[p] - t * brr[p - i]) % mod + mod) % mod;
        t = t * c % mod;
    }

    for(int i = 1; i <= p; i++){
        brr[i] = (brr[i] + brr[i - 1]) % mod;
    }

    if(k < p){
        cout << brr[k];
        return 0;
    }

    int cp = pow(c, p, mod);
    int temp = pow(cp, k / p, mod);

    long long answer = (temp - 1) * brr[p] % mod;
    answer = answer * pow(cp - 1, mod - 2, mod) % mod;

    answer = (answer + temp * brr[k % p] % mod) % mod;

    cout << (arr[0] + answer) % mod;

    return 0;
}