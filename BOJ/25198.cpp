#include <iostream>
#include <queue>

using namespace std;

int bfs(vector<vector<int>>& tree, int src, int dst){

    vector<int> distance(tree.size(), -1);
    distance[src] = 1;

    queue<int> q;
    q.push(src);

    while(!q.empty()){

        int now = q.front();
        q.pop();

        if(now == dst){
            return distance[now];
        }

        for(int next : tree[now]){
            if(distance[next] == -1){
                distance[next] = distance[now] + 1;
                q.push(next);
            }
        }
    }

    return -1;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int s, c, h;
    cin >> s >> c >> h;

    vector<vector<int>> tree(n + 1);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    long long sc = bfs(tree, s, c);
    long long ch = bfs(tree, c, h);
    long long sh = bfs(tree, s, h);

    long long x = (sc + ch + 1 - sh) / 2;

    long long answer = sc * (sc - 1) / 2 + ch * (ch - 1) / 2 + (sc - x) * (ch - x);
    cout << answer;

    return 0;
}