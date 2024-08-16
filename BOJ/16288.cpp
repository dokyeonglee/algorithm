#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(auto& a : arr){
        cin >> a;
    }

    vector<int> v;

    v.push_back(-1);

    for(int i = n - 1; i >= 0; i--){
        if(v.back() < arr[i]){
            v.push_back(arr[i]);
        }else{
            auto it = lower_bound(v.begin(), v.end(), arr[i]);
            *it = arr[i];
        }
    }

    if(v.size() - 1 <= k){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}