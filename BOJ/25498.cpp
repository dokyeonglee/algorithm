#include <iostream>
#include <queue>

using namespace std;

string bfs(string& str, vector<vector<int>>& tree){

    vector<bool> visited(tree.size());
    visited[1] = true;

    queue<int> q;
    q.push(1);

    string result = "";
    result += str[0];

    while(!q.empty()){
        int sz = q.size();
        queue<int> temp;
        char c = 0;
        while(sz--){
            int now = q.front();
            q.pop();
            for(auto& next : tree[now]){
                if(!visited[next] and str[next - 1] >= c){
                    c = str[next - 1];
                    visited[next] = true;
                    temp.push(next);
                }
            }
        }
        if(!temp.empty()){
            result += c;
            while(!temp.empty()){
                if(str[temp.front() - 1] == c){
                    q.push(temp.front());
                }
                temp.pop();
            }
        }
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string str;
    cin >> str;

    vector<vector<int>> tree(n + 1);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    cout << bfs(str, tree);

    return 0;
}