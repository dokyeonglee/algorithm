#include <iostream>
#include <vector>

using namespace std;

long long pow(long long a, long long n, long long mod){
    if(n <= 0){
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

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        cout << pow(2, n - 2, 1e9 + 7) << "\n";
    }

    return 0;
}