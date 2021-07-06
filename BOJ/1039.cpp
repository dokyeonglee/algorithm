#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int bfs(string n, int k){
	
	queue<string> q;
	q.push(n);
	
	int result = -1;
	int cnt = k - 1;
	int m = n.size();
	
	while(!q.empty() and cnt >= 0){
		
		int sz = q.size();
		map<string, bool> visited;
		
		for(int k = 0; k < sz; k++){
			
			string now = q.front();
			q.pop();
			
			for(int i = 0; i < m - 1; i++){
				for(int j = i + 1; j < m; j++){
					
					if(i == 0 and now[j] == '0'){
						continue;
					}
					
					swap(now[i], now[j]);
					
					if(!visited[now]){
						if(cnt == 0){
							result = max(result, stoi(now));
						}
						visited[now] = true;
						q.push(now);
					}
					
					swap(now[i], now[j]);
					
				}	
			}
			
		}
		
		cnt--;
		
	}
	
	return result;
	
}

int main() {
	
	string n;
	int k;
	cin >> n >> k;
		
	cout << bfs(n, k);
	
	return 0;
}