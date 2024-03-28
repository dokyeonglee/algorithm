#include <iostream>
#include <vector>

using namespace std;

long long pow(long long a, long long n, long long mod){
    if(n == 0){
        return 1;
    }
    auto result = pow(a, n / 2, mod);
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

    int mod = 1e9 + 7;

    while(t--){

        int n;
        cin >> n;
        
        vector<int> factor_cnt(1000);

        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            for(int i = 2; i * i <= x; i++){
                int cnt = 0;
                while(x % i == 0){
                    cnt++;
                    x /= i;
                }
                factor_cnt[i] = max(factor_cnt[i], cnt);
            }
            if(x > 1){
                factor_cnt[x] = max(factor_cnt[x], 1);
            }
        }

        long long answer = 1;
        for(int i = 2; i < 1000; i++){
            if(factor_cnt[i]){
                answer = answer * pow(i, factor_cnt[i], mod) % mod;
            }
        }
        cout << answer << "\n";

    }

    return 0;
}