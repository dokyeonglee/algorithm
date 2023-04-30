#include <iostream>
#include <queue>

using namespace std;

void topology_sort(vector<vector<int>>& graph, vector<int>& in_degree){

    vector<int> result(graph.size());

    queue<int> q;
    for(int i = 1; i < graph.size(); i++){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }

    for(int i = 1; i < graph.size(); i++){
        int now = q.front();
        q.pop();
        result[i] = now;
        for(int next : graph[now]){
            if(--in_degree[next] == 0){
                q.push(next);
            }
        }
    }

    for(int i = 1; i < graph.size(); i++){
        cout << result[i] << " ";
    }

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    vector<int> brr(n + 1);
    vector<int> crr(n + 1);

    int x;

    for(int i = 1; i <= n; i++){
        cin >> x;
        arr[x] = i;
    }

    for(int i = 1; i <= n; i++){
        cin >> x;
        brr[x] = i;
    }

    for(int i = 1; i <= n; i++){
        cin >> x;
        crr[x] = i;
    }

    vector<vector<int>> graph(n + 1);
    vector<int> in_degree(n + 1);

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            int cnt = (arr[i] > arr[j]) + (brr[i] > brr[j]) + (crr[i] > crr[j]);
            if(cnt > 1){
                graph[j].push_back(i);
                in_degree[i]++;
            }else{
                graph[i].push_back(j);
                in_degree[j]++;
            }
        }
    }

    topology_sort(graph, in_degree);

    return 0;
}