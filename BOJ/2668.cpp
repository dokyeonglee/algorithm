#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<int>& arr, vector<bool>& visited, int curr, int target){
	if(!visited[curr]){
		visited[curr] = true;
		return dfs(arr, visited, arr[curr], target);
	}else{
		return curr == target;
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> arr(n + 1);
	
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	
	vector<int> answer;
	
	for(int i = 1; i <=n; i++){
		vector<bool> visited(n + 1, false);
		if(dfs(arr, visited, i, i)){
			answer.push_back(i);
		}
	}	
		
	cout << answer.size() << "\n";
	for(int num : answer){
		cout << num << "\n";
	}
	
	return 0;
}