#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int d;
	cin >> d;
	
	int n;
	cin >> n;
	
	vector<long long> pos(n + 2);
	vector<long long> fix_time(n + 2);
	
	for(int i = 1; i <= n + 1; i++){
		cin >> pos[i];
		pos[i] += pos[i - 1];
	}
	
	for(int i = 1; i <= n; i++){
		cin >> fix_time[i];
	}
	
	vector<long long> time_dp(n + 2, 1e10);
	vector<int> prev(n + 2);
	
	time_dp[0] = 0;
	
	for(int i = 1; i <= n + 1; i++){
		for(int j = 0; j < i; j++){
			if(pos[i] - pos[j] <= d and time_dp[i] > time_dp[j] + fix_time[i]){
				prev[i] = j;			
				time_dp[i] = time_dp[j] + fix_time[i];
			}
		}
	}
	
	vector<int> answer;
	
	int now = n + 1;
	
	while(prev[now]){
		answer.push_back(prev[now]);
		now = prev[now];
	}
	
	cout << time_dp[n + 1] << "\n" << answer.size() << "\n";
	
	for(int i = answer.size() - 1; i >= 0; i--){
		cout << answer[i] << " ";
	}
	
	return 0;
}