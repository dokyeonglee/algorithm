#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<vector<int>> arr(n + 1, vector<int>(m + 1));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> arr[i][j];
			arr[i][j] += arr[i][j - 1];
		}
	}
	
	long long answer = 0;
	
	for(int i = 1; i <= m; i++){
		for(int j = i; j <= m; j++){
			long long sum = 0;
			map<long long, long long> cnt;
			for(int r = 1; r <= n; r++){
				sum += arr[r][j] - arr[r][i - 1];
				sum %= k;
				sum = (sum + k) % k;
				cnt[sum]++;
			}

			for(auto it : cnt){
				answer += it.second * (it.second - 1) / 2;
			}
			
			answer += cnt[0];
		}
	}
	
	
	cout << answer;
	
	return 0;
}