#include <iostream>
#include <queue>
#include <map>

using namespace std;

string topology_sort(vector<vector<int>>& adj, vector<int>& in_degree){

    queue<int> q;
    for(int i = 1; i < adj.size(); i++){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }

    for(int i = 1; i < adj.size(); i++){
        if(q.empty()){
            return "impossible";
        }
        int now = q.front();
        q.pop();
        for(int& next : adj[now]){
            if(--in_degree[next] == 0){
                q.push(next);
            }
        }
    }

    return "possible";
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<string, int> dwarf_to_int;

    vector<vector<int>> adj(2 * n + 1);
    vector<int> in_degree(2 * n + 1);

    int sz = 0;

    for(int i = 0; i < n; i++){

        string dwarf1, dwarf2;
        char o;
        cin >> dwarf1 >> o >> dwarf2;

        if(dwarf_to_int.count(dwarf1) == 0){
            dwarf_to_int[dwarf1] = ++sz;
        }

        if(dwarf_to_int.count(dwarf2) == 0){
            dwarf_to_int[dwarf2] = ++sz;
        }

        int u = dwarf_to_int[dwarf1];
        int v = dwarf_to_int[dwarf2];

        if(o == '<'){
            adj[u].push_back(v);
            in_degree[v]++;
        }else{
            adj[v].push_back(u);
            in_degree[u]++;
        }

    }

    adj.resize(sz + 1);
    in_degree.resize(sz + 1);

    cout << topology_sort(adj, in_degree);

    return 0;
}