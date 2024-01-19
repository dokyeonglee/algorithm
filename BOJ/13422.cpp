#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n, m, k;
        cin >> n >> m >> k;

        vector<int> arr(2 * n + 1);
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
            arr[i + n] = arr[i];
        }

        for(int i = 1; i <= 2 * n; i++){
            arr[i] += arr[i - 1];
        }

        int answer = 0;

        if(n == m){
            answer = (arr[n] < k);
        }else{
            for(int i = m; i < n + m; i++){
                if(arr[i] - arr[i - m] < k){
                    answer++;
                }
            }
        }

        cout << answer << "\n";
    }

    return 0;
}