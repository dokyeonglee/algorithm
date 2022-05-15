#include <iostream>
#include <vector>
#include <map>

using namespace std;

int sum(vector<vector<int>>& arr, int x, int y, int a, int b){
	return arr[a][b] - arr[x - 1][b] - arr[a][y - 1] + arr[x - 1][y - 1];	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> arr(n + 1, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> arr[i][j];
			arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
		}
	}
	
	map<int, int> cnt;
	int answer = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cnt.clear();
			for(int x = i + 1; x <= n; x++){
				for(int y = j + 1; y <= n; y++){
					cnt[sum(arr, i + 1, j + 1, x, y)]++;
				}
			}
			for(int x = i; x >= 1; x--){
				for(int y = j; y >= 1; y--){
					answer += cnt[sum(arr, x, y, i, j)];
				}
			}
			cnt.clear();
			for(int x = i; x >= 1; x--){
				for(int y = j; y <= n; y++){
					cnt[sum(arr, x, j, i, y)]++;
				}
			}
			for(int x = i + 1; x <= n; x++){
				for(int y = j - 1; y >= 1; y--){
					answer += cnt[sum(arr, i + 1, y, x, j - 1)];
				}
			}
		}
	}
	
	cout << answer;
	
	return 0;
}