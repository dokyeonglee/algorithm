#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const int mod = 1e9 + 7;

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> pow(n);

    pow[0] = 1;

    for(int i = 1; i < n; i++){
        pow[i] = pow[i - 1] * 2 % mod;
    }

    int answer = 0;

    for(int i = n - 1; i >= 0; i--){
        if(arr[i] != k){
            answer = (answer + pow[i]) % mod;
            k ^= arr[i];
        }
    }

    cout << answer;

    return 0;
}