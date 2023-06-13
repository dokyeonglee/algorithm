#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int>& arr, vector<int>& brr){
    int result = 0;
    int idx = 0;
    int idx2 = 0;
    while(idx < arr.size() and idx2 < brr.size()){
        if(arr[idx] < brr[idx2]){
            result++;
            idx++;
        }
        idx2++;
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> male(2);
    vector<vector<int>> female(2);

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        male[x > 0].push_back(-abs(x));
    }

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        female[x > 0].push_back(-abs(x));
    }

    sort(male[0].begin(), male[0].end());
    sort(male[1].begin(), male[1].end());
    sort(female[0].begin(), female[0].end());
    sort(female[1].begin(), female[1].end());

    cout << solve(male[0], female[1]) + solve(female[0], male[1]);

    return 0;
}