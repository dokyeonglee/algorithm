#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool possible(vector<int>& arr, vector<int>& start, int t, int foo){
    for(int i = 1; i < arr.size(); i++){
        int s;
        if(i <= foo){
            s = max(arr[i] - t + 1, 1);
        }else{
            s = max(arr[i] - t + 1, max(1, start[i - foo] + t));
        }
        if(!(s <= arr[i] and arr[i] <= s + t - 1)){
            return false;
        }
        start[i] = s;
    }
    return true;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    vector<int> arr(n + 1);
    vector<int> start(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    sort(arr.begin() + 1, arr.end());

    int left = 1;
    int right = n;

    int answer = n;

    while(left <= right){
        int mid = (left + right) / 2;
        if(possible(arr, start, t, mid)){
            answer = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }

    cout << answer;

    return 0;
}