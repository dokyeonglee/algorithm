#include <iostream>
#include <vector>
#include <map>

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

    map<int, int> cnt;

    long long n, m;
    cin >> n >> m;

    const int mod = 1e9 + 7;
    
    for(int i = 2; i * i <= n; i++){
        while(n % i == 0){
            cnt[i]++;
            n /= i;
        }
    }

    long long answer = 1;

    if(n > 1){
        cnt[n]++;
    }

    for(auto& it : cnt){
        if(it.second){
            long long a = (pow(it.first, it.second * m + 1, mod) - 1) * pow(it.first - 1, mod - 2, mod) % mod;
            answer = (answer * a) % mod;
        }
    }

    cout << answer;

    return 0;

}