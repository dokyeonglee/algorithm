#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<pair<int, int>>> arr(2001);

    for(int i = 1; i <= n; i++){
        int c, x;
        cin >> c >> x;
        arr[x].push_back(make_pair(c, i));
    }

    vector<int> answer(n + 1);

    vector<int> color_sum(n + 1);

    int total_sum = 0;

    for(int i = 1; i <= 2000; i++){
        total_sum += arr[i - 1].size() * (i - 1);
        for(int j = 0; j < arr[i].size(); j++){
            answer[arr[i][j].second] = total_sum - color_sum[arr[i][j].first];
        }
        for(int j = 0; j < arr[i].size(); j++){
            color_sum[arr[i][j].first] += i;
        }
    }

    for(int i = 1; i <= n; i++){
        cout << answer[i] << "\n";
    }    
    
    return 0;
}