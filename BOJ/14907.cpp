#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> in_degree(26);
    vector<vector<int>> graph(26);
    vector<int> times(26);
    vector<int> result(26);
    vector<bool> check(26);

    string str;

    while(getline(cin, str, '\n')){

        stringstream ss(str);
        vector<string> split;
        string temp;

        while(getline(ss, temp, ' ')){
            split.push_back(temp);
        }

        times[split[0][0] - 'A'] = stoi(split[1]);
        check[split[0][0] - 'A'] = true;
        
        if(split.size() == 3){
            for(int i = 0; i < split[2].size(); i++){
                graph[split[0][0] - 'A'].push_back(split[2][i] - 'A');
                in_degree[split[2][i] - 'A']++;
                check[split[2][i] - 'A'] = true;
            }
        }
    }

    queue<int> q;
    for(int i = 0; i < 26; i++){
        if(check[i] and in_degree[i] == 0){
            result[i] = times[i];
            q.push(i);
        }
    }

    int answer = 0;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        answer = max(answer, result[now]);
        for(int next : graph[now]){
            result[next] = max(result[next], result[now]);
            if(--in_degree[next] == 0){
                result[next] += times[next];
                q.push(next);
            }
        }
    }

    cout << answer;

    return 0;
}