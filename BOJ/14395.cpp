#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

string operators = "*+-/";

long long cal(long long x, char op){
	switch(op){
		case '*':
			return x * x;
		case '+':
			return x + x;
		case '-':
			return x - x;
		case '/':
			return x / x;
	}
}

string bfs(int s, int t){
	
	if(s == t){
		return "0";
	}
	
	set<long long> visited;
	visited.insert(s);
	
	queue<pair<long long, string>> q;
	q.push(make_pair(s, ""));
	
	while(!q.empty()){
		long long now = q.front().first;
		string path = q.front().second;
		q.pop();
		
		if(now == t){
			return path;
		}
		
		for(char op : operators){
			long long next = cal(now, op);
			if(next > 0 and visited.find(next) == visited.end()){
				visited.insert(next);
				q.push(make_pair(next, path + op));
			}
		}
	}
	
	return "-1";
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int s, t;
	cin >> s >> t;
	
	cout << bfs(s, t);
	
	return 0;
}