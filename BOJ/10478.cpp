#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b){
    return b ? gcd(b, a % b) : a;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1){

        int n;
        cin >> n;
        
        if(n == 0){
            break;
        }

        vector<string> brr(n);
        map<string, int> idx;

        for(int i = 0; i < n; i++){
            cin >> brr[i];
            idx[brr[i]] = i;
        }

        vector<vector<long long>> arr(n, vector<long long>(n));
        for(int i = 0; i < n - 1; i++){
            string str1, _, str2;
            int x;
            cin >> str1 >> _ >> x >> str2;
            arr[idx[str1]][idx[str2]] = x;
            arr[idx[str2]][idx[str1]] = -x;
        }

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(arr[i][k] > 0 and arr[k][j] > 0){
                        arr[i][j] = arr[i][k] * arr[k][j];
                    }
                    if(arr[i][k] > 0 and arr[k][j] < 0){
                        if(arr[i][k] < -arr[k][j]){
                            arr[i][j] = arr[k][j] / arr[i][k];
                        }else{
                            arr[i][j] = arr[i][k] / -arr[k][j];
                        }
                    }
                    if(arr[i][k] < 0 and arr[k][j] > 0){
                        if(-arr[i][k] < arr[k][j]){
                            arr[i][j] = arr[k][j] / -arr[i][k];
                        }else{
                            arr[i][j] = arr[i][k] / arr[k][j];
                        }
                    }
                    if(arr[i][k] < 0 and arr[k][j] < 0){
                        arr[i][j] = -(arr[i][k] * arr[k][j]);
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            bool check = true;
            for(int j = 0; j  < n; j++){
                if(arr[i][j] < 0){
                    check = false;
                    break;
                }
            }
            if(check){
                vector<pair<int, string>> answer(n);
                for(int j = 0; j < n; j++){
                    answer[j] = make_pair(arr[i][j], brr[j]);
                }
                sort(answer.begin(), answer.end());
                for(int j = 0; j < n; j++){
                    cout << answer[j].first << answer[j].second;
                    if(j != n - 1) cout << " = ";
                }
                cout << "\n";
                break;
            }

        }
    }

    return 0;
}