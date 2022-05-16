#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;


string str = "12345678";

int bfs(string x, int k){
	
	set<string> visited;
	visited.insert(x);
	
	queue<pair<int, string>> q;
	q.push(make_pair(0, x));
	
	string sorted = str.substr(0, x.size());
	
	while(!q.empty()){
		int cnt = q.front().first;
		auto now = q.front().second;
		q.pop();
		if(now == sorted){
			return cnt;
		}
		for(int i = 0; i + k <= x.size(); i++){
			auto next = now;
			reverse(next.begin() + i, next.begin() + i + k);
			if(visited.count(next) == 0){
				visited.insert(next);
				q.push(make_pair(cnt + 1, next));
			}
		}
		
	}
	return -1;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	string x(n, '1');
	for(int i = 0; i < n; i++){
		cin >> x[i];
	}
	
	cout << bfs(x, k);
	
	return 0;
}