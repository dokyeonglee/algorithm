#include <iostream>
#include <vector>

using namespace std;

int N, S;

int dfs(vector<int>& arr, int idx, int sum){
	
	int result = 0;
	
	if(idx == N){
		return sum == S;
	}
	
	result += dfs(arr, idx + 1, sum + arr[idx]);
	result += dfs(arr, idx + 1, sum);
	
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> S;
	
	vector<int> arr(N);
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	
	int answer = dfs(arr, 0, 0) - (S == 0);
	cout << answer;
	
	return 0;
}