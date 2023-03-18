#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> is_prime(2e6 + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i * i <= 2e6; i++){
        if(is_prime[i]){
            for(int j = i * i; j <= 2e6; j += i){
                is_prime[j] = false;
            }
        }
    }

    vector<int> prime;
    for(int i = 2; i < 2e6; i++){
        if(is_prime[i]){
            prime.push_back(i);
        }
    }

    int t;
    cin >> t;

    while(t--){

        long long a, b;
        cin >> a >> b;

        long long n = a + b;

        if(n == 2){
            cout << "NO\n";
        }else if(n % 2 == 0){
            cout << "YES\n";
        }else{
            n -= 2;
            if(n < is_prime.size()){
                if(is_prime[n]){
                    cout << "YES\n";
                }else{
                    cout << "NO\n";
                }
            }else{
                bool check = true;
                for(int i = 0; i < prime.size(); i++){
                    if(n % prime[i] == 0){
                        check = false;
                        break;
                    }
                }
                if(check){
                    cout << "YES\n";
                }else{
                    cout << "NO\n";
                }
            }
        }

    }

    return 0;
}