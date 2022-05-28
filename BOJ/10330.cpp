#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int n, int src, int dst1, int dst2){
	
	vector<bool> visited(1 << 16, false);
	visited[src] = true;
	
	queue<pair<int, int>> q;
	q.push(make_pair(src, 0));
	
	while(!q.empty()){
		
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(now == dst1 or now == dst2){
			return cnt;
		}
		
		for(int i = 1; i < n; i++){
			if(((now & (1 << i)) == 0) != ((now & (1 << (i - 1))) == 0)){
				int next = now ^ ((1 << (i - 1)) | (1 << i));
				if(!visited[next]){
					visited[next] = true;
					q.push(make_pair(next, cnt + 1));
				}
			}
		}
		
	}
	
	return -1;
}

int main() {
		
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	if(n == 1){
		cout << 0;
		return 0;
	}
	
	int src = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		src = (src << 1) | x;
	}
	
	int dst1 = 0;
	int dst2;
	
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		dst1 = (dst1 << x) | (((1 << x) - 1) * !(dst1 & 1));
	}
	
	dst2 = ~dst1 & ((1 << n) - 1);
	
	cout << bfs(n, src, dst1, dst2);
	
	return 0;
}