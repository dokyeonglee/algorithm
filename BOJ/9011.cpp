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

        vector<int> answer(n);
        vector<bool> check(n + 1, true);
        bool possilbe = true;

        for(int i = n - 1; i >= 0; i--){
            int cnt = 0;
            possilbe = false;
            for(int j = 1; j <= n; j++){
                if(check[j]){
                    cnt++;
                }
                if(cnt == arr[i] + 1){
                    answer[i] = j;
                    check[j] = false;
                    possilbe = true;
                    break;
                }
            }
            if(!possilbe){
                break;
            }
        }

        if(!possilbe){
            cout << "IMPOSSIBLE\n";
        }else{
            for(int i = 0; i < n; i++){
                cout << answer[i] << " ";
            }
            cout << "\n";
        }

    }

    return 0;
}