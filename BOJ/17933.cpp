#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);

    for(auto& a : arr){
        cin >> a;
    }

    vector<long long> brr(n);

    brr[0] = arr[0];

    for(int i = 1; i < n; i++){
        brr[i] += arr[i] + brr[i - 1] / 2;
        brr[i - 1] %= 2;
    }

    vector<bool> check(n);

    for(int i = n - 1; i > 0; i--){
        brr[i] -= arr[i];
        if(arr[i] % 2 == 0 or brr[i] > 0){
            brr[i - 1] += 2 * brr[i];
        }else{
            check[i] = true;
        }
    }

    const int mod = 1e9 + 7;

    int p = 1;

    long long answer = brr[0] % 2;

    for(int i = 0; i < n; i++){
        if(check[i]){
            answer += p;
        }
        p = 2 * p % mod;
    }

    answer %= mod;

    cout << answer;

    return 0;
}