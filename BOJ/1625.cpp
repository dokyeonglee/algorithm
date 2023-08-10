#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; 
    cin >> n >> m;

    vector<vector<int>> src(n, vector<int>(m));
    vector<vector<int>> dst(src);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> src[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> dst[i][j];
        }
    }

    if(src == dst){
        cout << 0;
        return 0;
    }

    vector<int> row_button(n);
    auto temp(src);

    for(int c = 0; c < m; c++){

        for(int k = 0; k < n; k++){
            row_button[k] = (src[k][c] ^ dst[k][0]);
        }

        temp = src;
        vector<pair<int, int>> answer;

        for(int i = 0; i < n; i++){
            if(row_button[i] == 1){
                answer.push_back(make_pair(0, i + 1));
                for(int j = 0; j < m; j++){
                    temp[i][j] ^= 1;
                }
            }
        }

        int cnt = 0;

        for(int i = 0; i < m; i++){
            for(int j = i; j < m; j++){
                bool check = true;
                for(int k = 0; k < n; k++){
                    if(dst[k][i] != temp[k][j]){
                        check = false;
                        break;
                    }
                }
                if(check){
                    cnt++;
                    if(i != j){
                        answer.push_back(make_pair(i + 1, j + 1));
                        for(int k = 0; k < n; k++){
                            swap(temp[k][i], temp[k][j]);
                        }
                    }
                    break;
                }
            }
        }

        if(cnt == m){
            cout << answer.size() << "\n";
            for(auto p : answer){
                if(p.first == 0){
                    cout << "0 " << p.second << "\n";
                }else{
                    cout << "1 " << p.first << " " << p.second << "\n";
                }
            }
            return 0;
        }
    }

    cout << -1;

    return 0;
}