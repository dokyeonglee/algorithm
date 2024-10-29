#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n, s;
        cin >> n >> s;

        vector<int> arr(n);

        for(auto& a : arr){
            cin >> a;
        }

        sort(arr.begin(), arr.end());

        int left = 1;
        int right = arr.back() - arr.front();

        int answer = 0;

        while(left <= right){

            int mid = (left + right) / 2;
            int cnt = 1;
            int now = arr[0];

            for(int i = 1; i < n; i++){
                if(arr[i] - now >= mid){
                    now = arr[i];
                    cnt++;
                }
            }

            if(cnt >= s){
                answer = mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }

        }

        cout << answer << "\n";
    }

    return 0;
}