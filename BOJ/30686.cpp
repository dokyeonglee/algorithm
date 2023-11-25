#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> d(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }

    int answer = 1e9;

    vector<vector<int>> arr(m + 1);

    for(int i = 1; i <= m; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int x;
            cin >> x;
            arr[i].push_back(x);
        }
    }

    vector<int> brr(m + 1);
    for(int i = 1; i <= m; i++){
        brr[i] = i;
    }

    do{
        vector<int> remember(n + 1);
        int result = 0;
        for(int i = 1; i <= m; i++){
            for(int& j : arr[brr[i]]){
                if(remember[j] < i){
                    result++;
                    remember[j] = i + d[j] - 1;
                }
            }
        }
        answer = min(answer, result);
    }while(next_permutation(brr.begin() + 1, brr.end()));

    cout << answer;

    return 0;
}