#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, pair<int, int>>> arr;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int x;
            cin >> x;
            arr.emplace_back(x, make_pair(i, j));
        }
    }

    sort(arr.rbegin(), arr.rend());

    int cnt = min(n * m, 5 * k - 4);

    int answer = 0;

    vector<vector<bool>> check(n + 2, vector<bool>(m + 2));

    for(int i = 0; i < (1 << cnt); i++){

        if(__builtin_popcount(i) > k){
            continue;
        }

        int result = 0;
        bool possible = true;

        for(int j = 0; j < cnt; j++){
            if(i & (1 << j)){
                result += arr[j].first;
                for(int d = 0; d < 4; d++){
                    if(check[arr[j].second.first + dr[d]][arr[j].second.second + dc[d]]){
                        possible = false;
                        break;
                    }
                }
                if(!possible){
                    break;
                }
                check[arr[j].second.first][arr[j].second.second] = true;
            }
        }

        if(possible){
            answer = max(answer, result);
        }

        for(int j = 0; j < cnt; j++){
            if(i & (1 << j)){
                check[arr[j].second.first][arr[j].second.second] = false;
            }
        }
        
    }

    cout << answer;

    return 0;
}