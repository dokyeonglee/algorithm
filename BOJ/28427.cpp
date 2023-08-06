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

    vector<int> arr(1e6 + 1);
    for(int i = 1; i < 5e5; i++){
        arr[i + i + 1] = is_prime[i + i + 1];
    }

    for(int i = 1; i <= 1e6; i++){
        arr[i] += arr[i - 1];
    }

    int q;
    cin >> q;

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << arr[r + r - 1] - arr[l + l] << "\n";
    }

    return 0;
}