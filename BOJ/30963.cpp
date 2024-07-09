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

    const int mod = 1e9 + 7;

    int t;
    cin >> t;

    while(t--){

        long long p, c, n;
        cin >> p >> c >> n;

        if(n < c){
            for(int i = 1; i <= n; i++){
                cout << i * p % mod << "\n";
            }
        }else{

            vector<long long> dp(n + 1);

            for(int i = 1; i < c; i++){
                dp[i] = (dp[i - 1] + p) % mod;
            }

            long long q_power_c = pow(mod + 1 - p, c, mod);
            long long q_power_c_times_p = q_power_c * p % mod;
            long long epected_value_last_c_steps =  ((mod + 1 - p) * dp[c - 1] + (dp[c - 1] + 1) * p) % mod;

            dp[c] = (q_power_c + epected_value_last_c_steps) % mod;

            for(int i = c + 1; i <= n; i++){
                epected_value_last_c_steps = epected_value_last_c_steps * (mod + 1 - p);
                epected_value_last_c_steps += (dp[i - 1] + 1) * p;
                epected_value_last_c_steps -= (dp[i - c - 1] + 1) * q_power_c_times_p;
                epected_value_last_c_steps = (mod + epected_value_last_c_steps % mod) % mod;
                dp[i] = ((dp[i - c] + 1) * q_power_c + epected_value_last_c_steps)% mod;
            }
            for(int k = 1; k <= n; k++){
                cout << dp[k] << "\n";
            }
        }
    }

    return 0;
}