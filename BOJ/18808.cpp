#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>>& arr){
    vector<vector<int>> result(arr[0].size(), vector<int>(arr.size()));
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[0].size(); j++){
            result[j][arr.size() - 1 - i] = arr[i][j];
        }
    }
    return result;
}

pair<int, int> get_pos(vector<vector<int>>& laptop, vector<vector<int>>& sticker){
    for(int i = 0; i + sticker.size() <= laptop.size(); i++){
        for(int j = 0; j + sticker[0].size() <= laptop[0].size(); j++){
            bool check = true;
            for(int r = 0; r < sticker.size(); r++){
                for(int c = 0; c < sticker[0].size(); c++){
                    if(laptop[i + r][j + c] == 1 and sticker[r][c] == 1){
                        check = false;
                        break;
                    }
                }
                if(!check){
                    break;
                }
            }
            if(check){
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> laptop(n, vector<int>(m));

    for(int i = 0; i < k; i++){

        int r, c;
        cin >> r >> c;

        vector<vector<int>> sticker(r, vector<int>(c));

        for(int j = 0; j < r; j++){
            for(int k = 0; k < c; k++){
                cin >> sticker[j][k];
            }
        }

        pair<int, int> pos = get_pos(laptop, sticker);

        if(pos.first == -1){
            for(int j = 0; j < 3; j++){
                sticker = rotate(sticker);
                pos = get_pos(laptop, sticker);
                if(pos.first != -1){
                    break;
                }
            }
        }
        
        if(pos.first != -1){
            for(int j = pos.first; j < pos.first + sticker.size(); j++){
                for(int k = pos.second; k < pos.second + sticker[0].size(); k++){
                    laptop[j][k] += sticker[j - pos.first][k - pos.second];
                }
            }
        }
    }

    int answer = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            answer += laptop[i][j];
        }
    }

    cout << answer;

    return 0;
}