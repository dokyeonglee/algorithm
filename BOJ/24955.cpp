#include <iostream>
#include <queue>

using namespace std;

int go(int a, int b, int mod){

    long long result = a;

    int temp = b;

    while(temp > 0){
        result = 10 * result % mod;
        temp /= 10;
    }

    result = (result + b) % mod;

    return result;

}

int bfs(vector<vector<int>>& tree, vector<int>& arr, int src, int dst, int mod){

    vector<int> result(arr.size(), -1);
    result[src] = arr[src];

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto& next : tree[now]){
            if(result[next] == -1){
                result[next] = go(result[now], arr[next], mod);
                q.push(next);
            }
        }
    }

    return result[dst];

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const int mod = 1e9 + 7;

    int n, q;
    cin >> n >> q;

    vector<vector<int>> tree(n + 1);
    vector<int> arr(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    while(q--){
        int src, dst;
        cin >> src >> dst;
        cout << bfs(tree, arr, src, dst, mod) << "\n";
    }


    return 0;
}