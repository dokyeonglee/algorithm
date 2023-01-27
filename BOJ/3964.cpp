#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> is_prime(1e6 + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i * i <= 1e6; i++){
        if(is_prime[i]){
            for(int j = i * i; j <= 1e6; j += i){
                is_prime[j] = false;
            }
        }
    }

    vector<int> prime;
    
    for(int i = 2; i <= 1e6; i++){
        if(is_prime[i]){
            prime.push_back(i);
        }
    }

    int t;
    cin >> t;
    
    while(t--){
        long long n, k;
        cin >> n >> k;
        long long answer = 1e18;
        int idx = 0;
        while(k > 0 and idx < prime.size() and k >= prime[idx]){
            long long cnt = 0;
            while(k % prime[idx] == 0){
                k /= prime[idx];
                cnt++;
            }
            if(cnt > 0){
                long long cnt2 = 0;
                long long temp = n;
                while(temp >= prime[idx]){
                    cnt2 += temp / prime[idx];
                    temp /= prime[idx];
                }
                answer = min(answer, cnt2 / cnt);
            }
            idx++;
        }
        if(k > 1){
            long long cnt = 0;
            while(n >= k){
                cnt += n / k;
                n /= k;
            }
            answer = min(answer, cnt);
        }
        cout << answer << "\n";
    }

    return 0;
}