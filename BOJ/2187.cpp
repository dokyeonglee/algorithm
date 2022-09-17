#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    vector<pair<pair<int, int>, int>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first.second >> arr[i].first.first >> arr[i].second;
    }

    sort(arr.begin(), arr.end());

    int answer = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[j].first.first - arr[i].first.first >= b){
                continue;
            }
            if(abs(arr[j].first.second - arr[i].first.second) >= a){
                continue;
            }
            answer = max(answer, abs(arr[i].second - arr[j].second));
        }
    }

    cout << answer;

    return 0;
}
