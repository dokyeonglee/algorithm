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

    string str;
    cin >> str;

    int mod = 998244353;

    long long two = 1;
    long long eleven = pow(11, str.size() - 1, mod);
    long long eleven_inverse = pow(11, mod - 2, mod);

    long long answer = 0;

    for(int i = 0; i < str.size(); i++){
        answer = (answer + (str[i] - '0') * two * eleven % mod) % mod;
        two = 2 * two % mod;
        eleven = eleven_inverse * eleven % mod;
    }

    cout << answer;

    return 0;
}