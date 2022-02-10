#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool dfs(vector<vector<long long>>& arr, map<long long, bool>& visited, map<long long, long long>& d, long long x){
	for(int i = 0; i < arr[x].size(); i++){
		long long t = arr[x][i];
		if(visited[t]){
			continue;
		}
		visited[t] = true;
		if(d[t] == 0 or dfs(arr, visited, d, d[t])){
			d[t] = x;
			return true;
		}
	}
	return false;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<long long>> arr(n + 1);
	vector<pair<long long, long long>> temp(n + 1);
	
	for(int i = 1; i <= n; i++){
		long long a, b;
		cin >> a >> b;
		arr[i].push_back(a + b);
		arr[i].push_back(a * b);
		arr[i].push_back(a - b);
		temp[i] = make_pair(a, b);
	}
	
	map<long long, long long> d;
	map<long long, bool> visited;
	
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		visited.clear();
		if(dfs(arr, visited, d, i)){
			cnt++;
		}
	}
	
	if(cnt == n){
		vector<string> answer(n + 1);
		for(auto it : d){
			int idx = it.second;
			if(temp[idx].first + temp[idx].second == it.first){
				answer[idx] = to_string(temp[idx].first) + " + " + to_string(temp[idx].second) + " = " + to_string(it.first);
			}else if(temp[idx].first * temp[idx].second == it.first){
				answer[idx] = to_string(temp[idx].first) + " * " + to_string(temp[idx].second) + " = " + to_string(it.first);
			}else if(temp[idx].first - temp[idx].second == it.first){
				answer[idx] = to_string(temp[idx].first) + " - " + to_string(temp[idx].second) + " = " + to_string(it.first);
			}
		}
		for(int i = 1; i <= n; i++){
			cout << answer[i] << "\n";
		}
	}else{
		cout << "impossible";
	}
	
	return 0;
}