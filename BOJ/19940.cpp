#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dt[] = {-1, 1, -10, 10, 60};

vector<int> bfs(int n){
	
	vector<bool> visited(65, false);
	visited[0] = true;
	
	queue<pair<int, vector<int>>> q;
	q.push(make_pair(0, vector<int>(5)));
	
	while(!q.empty()){
		int now = q.front().first;
		vector<int> cnt = q.front().second;
		q.pop();
		if(now == n){
			return cnt;
		}
		for(int i = 0; i < 5; i++){
			int next = max(now + dt[i], 0);
			if(next < 0 or next > 60){
				continue;
			}
			if(!visited[next]){
				cnt[i]++;
				visited[next] = true;
				q.push(make_pair(next, cnt));
				cnt[i]--;
			}
		}
	}
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		int n;
		cin >> n;
		vector<int> answer = bfs(n % 60);
		cout << answer[4] + n / 60 << " ";
		for(int i = 3; i >= 0; i--){
			cout << answer[i] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}