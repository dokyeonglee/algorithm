#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> is_prime(5e5 + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i * i <= 5e5; i++){
        if(is_prime[i]){
            for(int j = i * i; j <= 5e5; j += i){
                is_prime[j] = false;
            }
        }
    }

    int n;
    cin >> n;

    vector<int> cnt(1e4 + 1);

    int sum = 0;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cnt[x]++;
        sum += x;
    }

    vector<long long> dp(sum + 1);
    
    dp[0] = 1;

    for(int k = 1; k <= 10000; k++){
        if(cnt[k] == 0){
            continue;
        }
        for(int i = sum; i >= k; i--){
            for(int j = 1; j <= cnt[k]; j++){
                if(i < k * j){
                    break;
                }
                dp[i] += dp[i - k * j];
            }
        }
    }

    long long answer = 0;

    for(int i = 2; i <= sum; i++){
        if(is_prime[i]){
            answer += dp[i];
        }
    }

    answer *= cnt[0] + 1;

    cout << answer;

    return 0;
}