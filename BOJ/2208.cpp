#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> psum(n + 1);
	vector<int> arr(n + 1);
	
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		psum[i] = arr[i] + psum[i - 1];
	}
	
	int answer = 0;
	int discard = 0;
	
	for(int i = m - 1; i < n; i++){
		discard = min(discard, psum[i - m + 1]);
		answer = max(answer, psum[i + 1] - discard);
	}
	
	cout << answer;
	
	return 0;
}