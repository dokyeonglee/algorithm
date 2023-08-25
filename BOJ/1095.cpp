#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    int s, f, m;
    cin >> s >> f >> m;

    if(m == 1){
        cout << 1;
        return 0;
    }

    vector<bool> is_prime(m + 1, true);
    is_prime[0] = is_prime[1] = false;

    vector<int> min_prime_factor(m + 1);

    for(int i = 2; i * i <= m; i++){
        if(is_prime[i]){
            for(int j = i * i; j <= m; j += i){
                min_prime_factor[j] = i;
                is_prime[j] = false;
            }
        }
    }

    vector<int> prime;
    for(int i = 2; i <= m; i++){
        if(is_prime[i]){
            min_prime_factor[i] = i;
            prime.push_back(i);
        }
    }

    vector<int> arr(m + 1);

    for(auto p : prime){

        long long temp = p;

        while(temp <= s + f){
            arr[p] += (s + f) / temp;
            temp *= p;
        }
        
        temp = p;

        while(temp <= s){
            arr[p] -= s / temp;
            temp *= p;
        }

        temp = p;

        while(temp <= f){
            arr[p] -= f / temp;
            temp *= p;
        }
    }

    for(int i = m; i >= 2; i--){

        int temp = i;
        bool check = true;

        while(temp > 1){

            int p = min_prime_factor[temp];
            int cnt = 0;

            while(temp % p == 0){

                temp /= p;

                if(++cnt > arr[p]){
                    check = false;
                    break;
                }
            }

            if(!check){
                break;
            }

        }

        if(check){
            cout << i;
            return 0;
        }
    }

    cout << 1;

    return 0;
}