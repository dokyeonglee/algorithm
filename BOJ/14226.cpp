#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int s){
	
	vector<vector<bool>> visited(2 * s + 1, vector<bool>(2 * s + 1, false));
	visited[1][0] = true;
	
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(1, 0)));
	
	while(!q.empty()){
		
		int cnt = q.front().first;
		int display = q.front().second.first;
		int clipboard = q.front().second.second;
		q.pop();
		
		if(display == s){
			return cnt;
		}
		
		if(display < s){
			if(!visited[display][display]){
				visited[display][display] = true;
				q.push(make_pair(cnt + 1, make_pair(display, display)));
			}
		}
		
		if(display > 0){
			if(!visited[display - 1][clipboard]){
				visited[display - 1][clipboard] = true;
				q.push(make_pair(cnt + 1, make_pair(display - 1, clipboard)));
			}
		}
		
		if(clipboard > 0 and display + clipboard <= s){
			if(!visited[display + clipboard][clipboard]){
				visited[display + clipboard][clipboard] = true;
				q.push(make_pair(cnt + 1, make_pair(display + clipboard, clipboard)));
			}
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int s;
	cin >> s;
	
	cout << bfs(s);
	
	return 0;
}