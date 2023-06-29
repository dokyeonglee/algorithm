#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, k, t;
    cin >> n >> k >> t;

    vector<long long> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for(int i = 1; i <= n; i++){
        arr[i] += arr[i - 1];
    }

    if(arr[n] % k != 0){
        cout << "NO";
        return 0;
    }

    for(int i = 1; i <= n and arr[i] <= t; i++){
        if(arr[i] == (n - i) * k - (arr[n] - arr[i])){
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    return 0;
}