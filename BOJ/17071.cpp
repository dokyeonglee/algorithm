#include <iostream>
#include <queue>

using namespace std;

int bfs(int src, int dst){
	
	vector<vector<int>> visited(5e5+1, vector<int>(2, -1));
	
	queue<pair<int, int>> q;
	q.push(make_pair(src, 0));
	
	while(!q.empty()){
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if(now < 0 or now > 5e5 or visited[now][cnt % 2] != -1){
			continue;
		}
		
		visited[now][cnt % 2] = cnt;
		
		q.push(make_pair(now - 1, cnt + 1));
		q.push(make_pair(now + 1, cnt + 1));
		q.push(make_pair(now * 2, cnt + 1));
	}
	
	for(int i = 0; i <= 5e5; i++){
		dst += i;
		if(dst > 5e5){
			break;
		}
		if(visited[dst][i % 2] != -1 and visited[dst][i % 2] <= i){
			return i;	
		}
	}
	
	return -1;
}

int main() {
	
	int n, k;
	cin >> n >> k;
	
	cout << bfs(n, k);
	
	return 0;
}