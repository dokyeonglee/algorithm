#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        int answer = 0;
        int max_mex = 1;

        for(int i = 1; i < (1 << 17); i = (i << 1) | 1){
            int mex = 0;
            vector<bool> check(n + 1);
            for(int j = 0; j < n; j++){
                if((arr[j] & i) > n) continue;
                check[arr[j] & i] = true;
            }
            for(int j = 0; j <= n; j++){
                if(!check[j]){
                    mex = j;
                    break;
                }
            }
            if(max_mex < mex){
                max_mex = mex;
                answer = i;
            }
        }

        cout << answer << "\n";

    }

    return 0;
}