#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	string king;
	cin >> king;
	
	map<string, long long> blood;
	blood[king] = 1ll << 60;
	
	map<string, long long> in_degree;
	map<string, vector<string>> graph;
	
	for(int i = 0; i < n; i++){
		string child, p1, p2;
		cin >> child >> p1 >> p2;
		graph[p1].push_back(child);
		graph[p2].push_back(child);
		in_degree[child] += 2;
	}
	
	queue<string> q;
	for(auto it : graph){
		if(in_degree[it.first] == 0){
			q.push(it.first);
		}
	}
	
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto next : graph[now]){
			blood[next] += blood[now] / 2;
			if(--in_degree[next] == 0){
				q.push(next);
			}
		}
	}
	
	long long max_blood = -1;
	string answer;
	for(int i = 0; i < m; i++){
		string name;
		cin >> name;
		if(max_blood < blood[name]){
			max_blood = blood[name];
			answer = name;
		}
	}
	
	cout << answer;
	
	return 0;
}