#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int w, n;
	cin >> w >> n;
	
	vector<int> weight(n);
	for(int i = 0; i < n; i++){
		cin >> weight[i];	
	}
	
	const int INF = 987654321;
	vector<int> dp(799995, INF);
	
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			int sum = weight[i] + weight[j];
			if(w <= sum){
				continue;
			}
			if(dp[w - sum] < i){
				cout << "YES\n";
				return 0;
			}
			dp[sum] = min(dp[sum], j);
		}
	}
	
	cout << "NO\n";
	
	return 0;
}