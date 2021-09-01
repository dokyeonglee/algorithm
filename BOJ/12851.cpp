#include <iostream>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> bfs(int src, int dst){
	
	vector<bool> visited(100001, false);
	visited[src] = true;
	
	queue<pair<int, int>> q;
	q.push(make_pair(0, src));
	
	int answer_sec = 987654321;
	int cnt = 0;
	
	while(!q.empty()){
		int sec = q.front().first;
		int now = q.front().second;
		q.pop();
		visited[now] = true;
		if(now == dst){
			if(answer_sec > sec){
				answer_sec = sec;
				cnt = 1;
			}else if(answer_sec == sec){
				cnt++;
			}
		}
		int next[] = {now - 1, now + 1, now * 2};
		for(int i = 0; i < 3; i++){
			if(next[i] < 0 or next[i] > 100000){
				continue;
			}
			if(!visited[next[i]]){
				q.push(make_pair(sec + 1, next[i]));
			}
		}
	}
	return make_pair(answer_sec, cnt);	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	pair<int, int> answer = bfs(n, k);
	cout << answer.first << "\n" << answer.second;
	
	return 0;
}