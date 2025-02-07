#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> arr(n);
    for(auto& a : arr){
        cin >> a;
    }

    sort(arr.begin(), arr.end());

    if(arr[0] > m){
        cout << 0;
        return 0;
    }

    int left = 1;
    int right = n;
    int answer = 0;

    while(left <= right){
        int mid = (left + right) / 2;
        long long t = 0;
        for(int i = mid - 1; i >= 0; i -= k){
            t += arr[i];
        }
        if(t <= m){
            answer = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    cout << answer;

    return 0;

}