#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int k, n;
	cin >> k >> n;
	
	vector<long long> arr(k);
	for(int i = 0; i < k; i++){
		cin >> arr[i];
		arr[i] = -arr[i];
	}
	
	priority_queue<long long> pq(arr.begin(), arr.end());
	
	for(int i = 0; i < n - 1; i++){
		long long now = -pq.top();
		pq.pop();
		for(int j = 0; j < k; j++){
			long long next = now * -arr[j];
			pq.push(-next);
			if(now % arr[j] == 0){
				break;
			}
		}
	}
	
	cout << -pq.top();
	
	return 0;
}