#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> arr(n * k);

    int idx = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            int x;
            cin >> x;
            arr[idx++] = make_pair(x, i);
        }
    }

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = 0;
    int answer = 1e9;

    vector<int> cnt(n + 1);

    cnt[arr[0].second]++;

    int c = 1;

    while(right < arr.size()){
        if(c == n){
            answer = min(answer, arr[right].first - arr[left].first);
            if(--cnt[arr[left++].second] == 0){
                c--;
            }
        }else{
            if(right == arr.size() - 1){
                break;
            }
            if(++cnt[arr[++right].second] == 1){
                c++;
            }
            
        }
    }

    cout << answer;

    return 0;
}