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

    const int mod = 1e9 + 3;

    long long n;
    cin >> n;

    long long answer = pow(3, n, mod);

    if(n % 2){
        answer += 1;
    }else{
        answer +=3;
    }

    cout << answer;

    return 0;
}