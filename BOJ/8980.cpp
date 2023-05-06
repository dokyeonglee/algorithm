#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, c;
    cin >> n >> c;

    int m;
    cin >> m;

    vector<pair<pair<int, int>, int>> arr(m);
    for(int i = 0; i < m; i++){
        cin >> arr[i].first.second >> arr[i].first.first >> arr[i].second;
    }

    sort(arr.begin(), arr.end());

    vector<int> max_box(n + 1);

    int answer = 0;
    
    for(int i = 0; i < m; i++){
        int s = arr[i].first.second;
        int e = arr[i].first.first;
        int b = arr[i].second;
        int x = min(c - *max_element(max_box.begin() + s, max_box.begin() + e), b);
        for(int j = s; j < e; j++){
            max_box[j] += x;
        }
        answer += x;
    }
    
    cout << answer;

    return 0;
}