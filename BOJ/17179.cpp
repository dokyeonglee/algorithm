#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, m, l;
    cin >> t >> m >> l;

    vector<long long> arr(m + 1);
    for(int i = 1; i <= m; i++){
        cin >> arr[i];
    }

    arr.push_back(l);

    while(t--){

        int q;
        cin >> q;

        int left = 0;
        int right = l / 2;

        int answer = -1;

        while(left <= right){

            int mid = (left + right) / 2;
            int cnt = 0;
            long long sum = 0;

            for(int i = 1; i <= m + 1; i++){
                if(sum + arr[i] - arr[i - 1] >= mid){
                    sum = 0;
                    cnt++;
                }else{
                    sum += arr[i] - arr[i - 1];
                }
            }
            if(cnt < q + 1){
                right = mid - 1;
            }else{
                answer = mid;
                left = mid + 1;
            }
        }

        cout << answer << "\n";
        
    }

    return 0;
}