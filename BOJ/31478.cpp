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

    long long a, b, c;
    cin >> a >> b >> c;

    int k, l;
    cin >> k >> l;

    int answer = ((k + pow(a, pow(b, c, 6), 7)) % 7 == l)
                + ((k + pow(b, c, 7) * pow(a, 5, 7)) % 7 == l) * 2;

    cout << answer;

    return 0;
}