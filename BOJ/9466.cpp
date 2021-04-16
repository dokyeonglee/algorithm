#include <iostream>
#include <vector>

using namespace std;

int cnt;

void dfs(vector<int>& arr, int now, vector<bool>& visited, vector<bool>& check){
	
	int next = arr[now];
	visited[now] = true;
	
	if(!visited[next]){
		dfs(arr, next, visited, check);
	}else{
		if(!check[next]){
			for(int i = next; i != now; i = arr[i]){
				cnt++;
			}
			cnt++;
		}	
	}
	
	check[now] = true;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		
		int n;
		cin >> n;
		
		vector<int> arr(n + 1);
		vector<bool> visited(n + 1, false);
		vector<bool> check(n + 1, false);
		
		for(int i = 1; i <= n; i++){
			cin >> arr[i];
		}
		
		cnt = 0;
		
		for(int i = 1; i <= n; i++){
			if(!visited[i]){
				dfs(arr, i, visited, check);
			}
		}
		
		cout << n - cnt << '\n';
		
	}
	
	return 0;
}