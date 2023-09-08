#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> is_prime(1e3 + 1, true);
    is_prime[0] = is_prime[1] = false;

    vector<int> prime;

    for(long long i = 2; i * i <= 1e3; i++){
        if(is_prime[i]){
            for(long long j = i * i; j <= 1e3; j += i){
                is_prime[j] = false;
            }
        }
    }

    prime.reserve(200);

    for(long long i = 2; i <= 1e3; i++){
        if(is_prime[i]){
            prime.push_back(i);
        }
    }

    int n;
    cin >> n;

    vector<map<int, int>> cnt(n);
    map<int, int> total;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        for(int j = 0; j < prime.size() and prime[j] <= x; j++){
            while(x % prime[j] == 0){
                x /= prime[j];
                cnt[i][prime[j]]++;
                total[prime[j]]++;
            }
        }
        if(x > 1){
            cnt[i][x]++;
            total[x]++;
        }
    }

    int answer = 0;
    long long gcd = 1;

    for(auto& it : total){
        gcd *= pow(it.first, it.second / n);
        for(int i = 0; i < n; i++){
            answer += max(0, it.second / n - cnt[i][it.first]);
        }        
    }

    cout << gcd << " " << answer;

    return 0;
}   