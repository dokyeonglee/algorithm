#include <iostream>
#include <queue>

using namespace std;

bool topology_sort(vector<vector<int>>& graph, vector<int>& in_degree){

    queue<int> q;

    for(int i = 0; i < graph.size(); i++){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }

    for(int i = 0; i < graph.size(); i++){

        if(q.empty()){
            return true;
        }

        int now = q.front();
        q.pop();

        for(int next : graph[now]){
            if(--in_degree[next] == 0){
                q.push(next);
            }
        }
    }

    return false;

}

vector<int> parsing(string& str, int c){

    vector<int> result;

    int row = 0;
    int col = -1;

    for(int i = 0; i < str.size(); i++){
        if(str[i] >= 'A' and str[i] <= 'Z'){
            col = (col + 1) * 26 + (str[i] - 'A');
        }else if(str[i] >= '0' and str[i] <= '9'){
            row = row * 10 + (str[i] - '0');
        }else{
            result.push_back((row - 1) * c + col);
            row = 0;
            col = -1;
        }
    }

    result.push_back((row - 1) * c + col);

    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;

    vector<vector<int>> graph(r * c);
    vector<int> in_degree(r * c);

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){

            string str;
            cin >> str;

            if(str == "."){
                continue;
            }

            vector<int> result = parsing(str, c);

            for(int k = 0; k < result.size(); k++){
                graph[result[k]].push_back(i * c + j);
                in_degree[i * c + j]++;
            }

        }
    }

    if(topology_sort(graph, in_degree)){
        cout << "yes";
    }else{
        cout << "no";
    }

    return 0;
}