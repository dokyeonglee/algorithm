#include <iostream>
#include <vector>

using namespace std;

int count_prime_factor(vector<int>& prime, int x){
    int result = 0;
    for(int i = 0; i < prime.size() and x >= prime[i] * prime[i]; i++){
        if(x % prime[i] == 0){
            result++;
            while(x % prime[i] == 0){
                x /= prime[i];
            }
        }
    }
    if(x > 1){
        result++;
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> is_prime(4e4, true);

    is_prime[0] = is_prime[1] = false;

    vector<int> prime;

    for(int i = 2; i < 4e4; i++){
        if(is_prime[i]){
            prime.push_back(i);
            for(int j = i * i; j < 4e4; j += i){
                is_prime[j] = false;
            }
        }
    }

    int t;
    cin >> t;

    while(t--){
        int k;
        cin >> k;
        int answer = count_prime_factor(prime, k) + count_prime_factor(prime, k + 1);
        cout << answer << "\n";
    }

    return 0;

}