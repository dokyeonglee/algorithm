#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const int n = 1e5;

    vector<bool> is_prime(n + 1, true);

    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i * i <= n; i++){
        if(is_prime[i]){
            for(int j = i * i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
    }

    vector<long long> phi(n + 1);

    for(int i = 1; i <= n; i++){
        phi[i] = i;
    }

    for(int i = 2; i <= n; i++){
        if(is_prime[i]){
            for(int j = i; j <= n; j += i){
                phi[j] = (i - 1) * (phi[j] / i);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        phi[i] += phi[i - 1];
    }

    int p, q;
    cin >> p >> q;

    cout << phi[q / p] + 1;

    return 0;
}