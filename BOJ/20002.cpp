#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> arr(n + 1, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> arr[i][j];
			arr[i][j] += arr[i -1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
		}
	}
	
	int answer = -987654321;
	for(int k = 1; k <= n; k++){
		for(int i = 1; i + k - 1 <= n; i++){
			for(int j = 1; j + k - 1 <= n; j++){
				answer = max(answer, arr[i + k - 1][j + k - 1] - arr[i - 1][j + k - 1] - arr[i + k - 1][j - 1] + arr[i - 1][j - 1]);
			}
		}
	}
	
	cout << answer;
	
	return 0;
}