#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int, pair<int, int>>> arr(n);
    for(auto& a : arr){
        cin >> a.second.first>> a.second.second >> a.first;
    }

    sort(arr.begin(), arr.end());

    int answer = 1e9;

    for(int i = 0; i < n; i++){
        int x = arr[i].second.first;
        for(int j = 0; j < n; j++){
            int y  = arr[j].second.second;
            int z = 1e9;
            int cnt = 0;
            for(int l = 0; l < n; l++){
                if(arr[l].second.first <= x and arr[l].second.second <= y){
                    z = arr[l].first;
                    if(++cnt == k){
                        break;
                    }
                }
            }
            if(cnt == k){
                answer = min(answer, x + y + z);
            }
        }
    }

    cout << answer;

    return 0;
}