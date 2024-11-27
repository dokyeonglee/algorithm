#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& tree, vector<bool>& answer, int now, int p){

    for(auto& next : tree[now]){
        if(next != p){
            answer[now] = answer[now] | !dfs(tree, answer, next, now);
        }
    }

    return answer[now];

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<bool> answer(n + 1);

    dfs(tree, answer, 1, -1);

    for(int i = 1; i <= n; i++){
        if(answer[i]){
            cout << "donggggas\n";
        }else{
            cout << "uppercut\n";
        }
    }

    return 0;
}