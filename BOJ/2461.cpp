#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    if(n == 1){
        cout << 0;
        return 0;
    }

    vector<pair<int, int>> arr(n * m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i * m + j].first;
            arr[i * m + j].second = i;
        }
    }

    sort(arr.begin(), arr.end());

    vector<int> check(n);
    check[arr[0].second] = 1;

    int left = 0;
    int right = 0;
    int cnt = 1;

    int answer = 1987654321;

    while(right < n * m - 1){
        if(cnt == n){
            answer = min(answer, arr[right].first - arr[left].first);
            if(--check[arr[left++].second] == 0){
                cnt--;
            }
        }else{
            while(right < n * m - 1 and cnt < n){
                if(check[arr[++right].second]++ == 0){
                    cnt++;
                }
            }
        }
    }

    while(cnt == n){
        answer = min(answer, arr[right].first - arr[left].first);
        if(--check[arr[left++].second] == 0){
            cnt--;
        }
    }

    cout << answer;
    
    return 0;
}