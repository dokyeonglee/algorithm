#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int dr[] = {-2, -1, 0, 1, 2};
int dc[] = {-2, -1, 0, 1, 2};

int bfs(set<pair<int, int>>& hole, int T){
	
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(0, 0)));
	
	int result = -1;
	
	while(!q.empty()){
		int cnt = q.front().first;
		auto now = q.front().second;
		q.pop();
		if(now.second == T){
			result = cnt;
			break;
		}
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++){
				auto next = make_pair(now.first + dr[i], now.second + dc[j]);
				if(hole.count(next)){
					q.push(make_pair(cnt + 1, next));
					hole.erase(next);
				}
			}
		}
	}
	
	return result;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, T;
	cin >> n >> T;
	
	set<pair<int, int>> hole;
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		hole.insert(make_pair(x, y));
	}
	
	cout << bfs(hole, T);
	
	return 0;
}