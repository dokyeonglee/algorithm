#include <iostream>
#include <queue>
#include <set>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(string& str){

    set<string> visited;
    visited.insert(str);

    queue<pair<string, pair<int, pair<int, int>>>> q;

    for(int i = 0; i < 9; i++){
        if(str[i] == '0'){
            q.push(make_pair(str, make_pair(0, make_pair(i / 3, i % 3))));
        }
    }

    while(!q.empty()){

        string state = q.front().first;
        int cnt = q.front().second.first;
        auto now = q.front().second.second;
        q.pop();

        if(state == "123456780"){
            return cnt;
        }

        for(int i = 0; i < 4; i++){
            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];
            if(next_r < 0 or next_r >= 3 or next_c < 0 or next_c >= 3){
                continue;
            }
            swap(state[now.first * 3 + now.second], state[next_r * 3 + next_c]);
            if(!visited.count(state)){
                visited.insert(state);
                q.push(make_pair(state, make_pair(cnt + 1, make_pair(next_r, next_c))));
            }
            swap(state[now.first * 3 + now.second], state[next_r * 3 + next_c]);
        }
        
    }

    return -1;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    pair<int, int> pos;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int x;
            cin >> x;
            if(x == 0){
                pos = make_pair(i, j);
            }
            str += '0' + x;
        }
    }
    
    cout << bfs(str);

    return 0;
}