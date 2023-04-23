#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> name(n);
    unordered_map<string, int> name_to_int;

    for(int i = 0; i < n; i++){
        cin >> name[i];
        name_to_int[name[i]] = i;
    }

    sort(name.begin(), name.end());

    for(int i = 0; i < n; i++){
        name_to_int[name[i]] = i;
    }

    int m;
    cin >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> in_degree(n + 1);

    for(int i = 0; i < m; i++){

        string _a, _b;
        cin >> _a >> _b;

        int a = name_to_int[_a];
        int b = name_to_int[_b];

        graph[b].push_back(a);
        in_degree[a]++;

    }

    queue<int> q;
    
    vector<int> root;
    for(int i = 0; i < n; i++){
        if(in_degree[i] == 0){
            root.push_back(i);
            q.push(i);
        }
    }

    vector<vector<int>> child(n + 1);

    while(!q.empty()){

        int now = q.front();
        q.pop();

        for(int next : graph[now]){
            if(--in_degree[next] == 0){
                child[now].push_back(next);
                q.push(next);
            }
        }
    }

    cout << root.size() << "\n";
    for(int i = 0; i < root.size(); i++){
        cout << name[root[i]] << " ";
    }

    cout << "\n";

    for(int i = 0; i < n; i++){
        int idx = name_to_int[name[i]];
        cout << name[i] << " " << child[idx].size() << " ";
        sort(child[idx].begin(), child[idx].end());
        for(int j = 0; j < child[idx].size(); j++){
            cout << name[child[idx][j]] << " ";
        }
        cout << "\n";
    }


    return 0;
}