#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(vector<int>& w, vector<bool>& visited){
	
	int result = 0;
	
	for(int i = 1; i < w.size() - 1; i++){
		
		if(visited[i]){
			continue;
		}
		
		int left = i - 1;
		int right = i + 1;
		
		while(visited[left]){
			left--;
		}
		
		while(visited[right]){
			right++;
		}
		
		visited[i] = true;
		result = max(result, dfs(w, visited) + w[left] * w[right]);
		visited[i] = false;
	}
	
	return result;
}

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> w(n);
	for(int i = 0; i < n; i++){
		cin >> w[i];
	}
	
	vector<bool> visited(n, false);
	
	cout << dfs(w, visited);
	
	return 0;
}