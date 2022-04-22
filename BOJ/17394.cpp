#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int n, vector<bool>& is_prime, int a, int b){
	
	vector<bool> visited(1000001, false);
	visited[n] = true;
	
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	
	int result = 987654321;
	
	while(!q.empty()){
		
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(now >=a and now <=b and is_prime[now]){
			result = min(result, cnt);
		}
		
		if(!visited[now / 2]){
			q.push(make_pair(now / 2, cnt + 1));
			visited[now / 2] = true;
		}
		if(!visited[now / 3]){
			q.push(make_pair(now / 3, cnt + 1));
			visited[now / 3] = true;
		}
		if(n + 1 <= 1000000 and !visited[now + 1]){
			q.push(make_pair(now + 1, cnt + 1));
			visited[now + 1] = true;
		}
		if(now > 0 and !visited[now - 1]){
			q.push(make_pair(now - 1, cnt + 1));
			visited[now - 1] = true;
		}
	}
	
	if(result == 987654321){
		result = -1;
	}
	
	return result;	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<bool> is_prime(1000001, true);
	is_prime[1] = false;
	
	for(int i = 2; i * i <= 1000000; i++){
		if(is_prime[i]){
			for(int j = i * i; j <= 1000000; j += i){
				is_prime[j] = false;
			}
		}
	}
	
	int T;
	cin >> T;
	
	while(T--){
		int n, a, b;
		cin >> n >> a >> b;
		cout << bfs(n, is_prime, a, b) << "\n";
	}
	
	return 0;
}