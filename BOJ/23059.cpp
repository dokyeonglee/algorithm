#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int cnt;
map<string, int> name_to_int;
vector<string> int_to_name(400001);

bool compare(pair<int, int> a, pair<int, int> b){
	if(a.first == b.first){
		return int_to_name[a.second] < int_to_name[b.second];
	}
	return a.first < b.first;
}

vector<pair<int, int>> topology_sort(vector<vector<int>>& graph, vector<int>& in_degree){
	
	vector<int> _result(400001);
	vector<pair<int, int>> result;
	
	
	queue<int> q;
	
	for(int i = 1; i <= cnt; i++){
		if(in_degree[i] == 0){
			q.push(i);
			_result[i] = 1;
			result.push_back(make_pair(1, i));
		}
	}
	
	
	for(int i = 1; i <= cnt; i++){
		
		if(q.empty()){
			return result;		
		}
		
		int now = q.front();
		q.pop();
		
		for(int i = 0; i < graph[now].size(); i++){
			int next = graph[now][i];
			if(--in_degree[next] == 0){
				q.push(next);
				_result[next] = _result[now] + 1;
				result.push_back(make_pair(_result[next], next));
			}
		}
		
	}
	
	return result;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> in_degree(400001);
	vector<vector<int>> graph(400001);
	
	for(int i = 0; i < n; i++){
		string u, v;
		cin >> u >> v;
		if(name_to_int[u] == 0){
			name_to_int[u] = ++cnt;
			int_to_name[cnt] = u;
		}
		if(name_to_int[v] == 0){
			name_to_int[v] = ++cnt;
			int_to_name[cnt] = v;
		}
		graph[name_to_int[u]].push_back(name_to_int[v]);
		in_degree[name_to_int[v]]++;
	}
	
	
	vector<pair<int, int>> answer = topology_sort(graph, in_degree);
	sort(answer.begin(), answer.end(), compare);
	
	if(answer.size() != name_to_int.size()){
		cout << -1;
	}else{
		for(int i = 0; i < answer.size(); i++){
			cout << int_to_name[answer[i].second] << "\n";
		}
	}
	
	return 0;

}