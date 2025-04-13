#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> is_composite(1e6 + 1);
    is_composite[0] = is_composite[1] = false;

    for(int i = 2; i * i <= 1e6; i++){
        if(!is_composite[i]){
            for(int j = i * i; j <= 1e6; j += i){
                is_composite[j] = true;
            }
        }
    }

    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto& a : arr){
        cin >> a;
    }

    if(is_sorted(arr.begin(), arr.end())){
        cout << "YES";
        return 0;
    }

    for(int i = 1; i < n; i++){
        if((arr[i - 1] > 1 and arr[i] > 1) or is_composite[arr[i - 1] * arr[i]]){
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    return 0;

}