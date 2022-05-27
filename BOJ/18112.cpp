#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int get_msb(int n){
	n |= (n >> 1);
	n |= (n >> 2);
	n |= (n >> 4);
	n |= (n >> 8);
	n |= (n >> 16);
	return n - (n >> 1);
}

int bfs(int l, int k){
	
	vector<bool> visited(2049, false);
	visited[l] = true;
	
	queue<pair<int, int>> q;
	q.push(make_pair(l, 0));
	
	while(!q.empty()){
		
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(now == k){
			return cnt;
		}
		
		int msb = get_msb(now);
		int bit = 1;
		
		while(bit < msb){
			if(!visited[now ^ bit]){
				visited[now ^ bit] = true;
				q.push(make_pair(now ^ bit, cnt + 1));
			}
			bit <<= 1;
		}
		
		if(now < 1024 and !visited[now + 1]){
			visited[now + 1] = true;
			q.push(make_pair(now + 1, cnt + 1));	
		}
		
		if(now > 0 and !visited[now - 1]){
			visited[now - 1] = true;
			q.push(make_pair(now - 1, cnt + 1));
		}
		
	}
	
	return -1;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string str, str2;
	cin >> str >> str2;
	
	int l = stoi(str, nullptr, 2);
	int k = stoi(str2, nullptr, 2);
	cout << bfs(l, k);
	
	return 0;
}