#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

vector<int> bfs(vector<string>& arr, vector<int>& s){

    int n = arr.size();
    int m = arr[0].size();

    vector<queue<pair<int, int>>> q(s.size());
    vector<int> result(s.size());

    int cnt = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] >= '1' and arr[i][j] <= '9'){
                q[arr[i][j] - '1'].push(make_pair(i, j));
                result[arr[i][j] - '1']++;
                cnt++;
            }else if(arr[i][j] == '#'){
                cnt++;
            }
        }
    }

    while(cnt < n * m){
        int temp = cnt;
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; !q[i].empty() and j < s[i] and cnt < n * m; j++){
                int sz = q[i].size();
                for(int k = 0; k < sz; k++){
                    auto now = q[i].front();
                    q[i].pop();
                    for(int a = 0; a < 4; a++){
                        int next_r = now.first + dr[a];
                        int next_c = now.second + dc[a];
                        if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
                            continue;
                        }
                        if(arr[next_r][next_c] == '.'){
                            arr[next_r][next_c] = '1' + i;
                            q[i].push(make_pair(next_r, next_c));
                            result[i]++;
                            cnt++;
                        }
                    }
                }
            }
        }
        if(temp == cnt){
            break;
        }
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, p;
    cin >> n >> m >> p;

    vector<int> s(p);
    for(int i = 0; i < p; i++){
        cin >> s[i];
    }

    vector<string> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> answer = bfs(arr, s);

    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }

    return 0;
}