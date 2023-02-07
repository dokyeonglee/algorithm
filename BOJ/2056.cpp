#include <iostream>
#include <queue>

using namespace std;

int topology_sort(vector<vector<int>>& graph, vector<int>& in_degree, vector<int>& time){

    vector<int> result(graph.size());

    queue<int> q;
    
    int answer = 0;
	
    for(int i = 1; i < graph.size(); i++){
        if(in_degree[i] == 0){
            result[i] = time[i];
            answer = max(answer, result[i]);
            q.push(i);
        }
    }

    for(int i = 1; i < graph.size(); i++){

        int now = q.front();
        q.pop();

        for(int next: graph[now]){
            result[next] = max(result[next], result[now]);
            if(--in_degree[next] == 0){
                result[next] += time[next];
                answer = max(answer, result[next]);
                q.push(next);
            }
        }

    }

    return answer;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> in_degree(n + 1);
    vector<int> time(n + 1);

    vector<vector<int>> graph(n + 1);

    for(int i = 1; i <= n; i++){

        cin >> time[i];

        int x;
        cin >> x;
        
        for(int j = 0; j < x; j++){
            int y;
            cin >> y;
            in_degree[i]++;
            graph[y].push_back(i);
        }
    }

    cout << topology_sort(graph, in_degree, time);
    
    return 0;
}