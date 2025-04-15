#include <iostream>
#include <vector>
#include <algorithm>

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

    sort(arr.begin(), arr.end());

    int min_mex = 0;
    int max_mex = 0;

    int mex = 0;

    if(arr[0] == 0){
        int cnt = 1;
        mex = 1;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] == arr[i - 1]){
                cnt++;
            }else{
                if(cnt <= k or arr[i] - arr[i - 1] > 1){
                    break;
                }
                cnt = 1;
            }
            mex = arr[i] + 1;
        }
        if(cnt <= k){
            mex--;
        }
    }

    min_mex = mex;

    mex = 0;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] - mex <= k){
            if(arr[i] > mex){
                k -= arr[i] - mex;
            }
            mex = arr[i] + 1;
        }else{
            break;
        }
    }

    max_mex = mex + k;

    cout << min_mex << "\n";
    cout << max_mex;

    return 0;

}