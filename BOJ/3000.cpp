#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<int, int>> arr(n);
	vector<long long> cnt_x(100001);
	vector<long long> cnt_y(100001);
	
	for(int i = 0; i < n; i++){
		cin >> arr[i].first >> arr[i].second;
		cnt_x[arr[i].first]++;
		cnt_y[arr[i].second]++;
	}
	
	long long answer = 0;
	
	for(int i = 0; i < n; i++){
		if(cnt_x[arr[i].first] > 1 and cnt_y[arr[i].second] > 1){
			answer += (cnt_x[arr[i].first] - 1) * (cnt_y[arr[i].second] - 1);
		}
	}
	
	cout << answer;
	
	return 0;
}