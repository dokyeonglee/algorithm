#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int l, n, k;
    cin >> l >> n >> k;

    vector<int> arr(n + 2);

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    arr[n + 1] = l;

    int left = 0;
    int right = l;

    int answer;

    while(left <= right){

        int mid = (left + right) / 2;
        int cnt = 0;
        int now = mid;

        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - arr[i - 1] > mid){
                cnt = k + 1;
                break;
            }
            if(arr[i] - arr[i - 1] <= now){
                now -= arr[i] - arr[i - 1];
            }else{
                now = mid - (arr[i] - arr[i - 1]);
                cnt++;
            }
        }
        
        if(cnt > k){
            left = mid + 1;
        }else{
            answer = mid;
            right = mid - 1;
        }
    }

    cout << answer;

    return 0;
}