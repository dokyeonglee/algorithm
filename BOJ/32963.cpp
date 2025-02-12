#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> arr(n);

    for(auto& p : arr){
        cin >> p.first;
    }

    for(auto&p : arr){
        cin >> p.second;
    }

    sort(arr.rbegin(), arr.rend());

    vector<pair<int, int>> queries(q);
    for(int i = 0; i < q; i++){
        cin >> queries[i].first;
        queries[i].second = i;
    }

    sort(queries.rbegin(), queries.rend());

    int idx = 0;
    int x = 0;
    int cnt = 0;

    vector<int> answer(q);

    for(int i = 0; i < q; i++){
        while(idx < n and arr[idx].first >= queries[i].first){
            if(arr[idx].second > x){
                x = arr[idx].second;
                cnt = 1;
            }else if(arr[idx].second == x){
                cnt++;
            }
            idx++;
        }
        answer[queries[i].second] = cnt;
    }

    for(int i = 0; i < q; i++){
        cout << answer[i] << "\n";
    }

    return 0;

}