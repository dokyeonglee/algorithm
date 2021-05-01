#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int n, int k){
	
	queue<int> q;
	vector<int> cnt(100001, 987654321);
	
	q.push(n);
	cnt[n] = 0;
	
	while(!q.empty()){
		
		int now = q.front();
		q.pop();
		
		if(now == k){ 
			return cnt[k];
		}
		
		int next[] = {now * 2, now + 1, now - 1};
		int cost[] = {0, 1, 1};
		
		for(int i = 0; i < 3; i++){
			if(next[i] >= 0 and next[i] < cnt.size() and cnt[now] + cost[i] < cnt[next[i]]){
				q.push(next[i]);
				cnt[next[i]] = cnt[now] + cost[i];
			}
		}
		
	}
}


int main() {
	
	int n, k;
	cin >> n >> k;
	
	cout << bfs(n, k);
	
	return 0;
}