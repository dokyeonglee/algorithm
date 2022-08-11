#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, c;
	cin >> n >> m >> c;
	
	deque<int> max_dq(m);
	deque<int> min_dq(m);
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	int cnt = 0;
	
	for(int i = 0; i < m; i++){
		while(!max_dq.empty() and arr[i] >= arr[max_dq.back()]){
			max_dq.pop_back();
		}
		while(!min_dq.empty() and arr[i] <= arr[min_dq.back()]){
			min_dq.pop_back();
		}
		max_dq.push_back(i);
		min_dq.push_back(i);
	}
	
	for(int i = m; i < n; i++){
		
		if(arr[max_dq.front()] - arr[min_dq.front()] <= c){
			cnt++;
			cout << i - m + 1 << "\n";
		}
		
		while(!max_dq.empty() and max_dq.front() <= i - m){
			max_dq.pop_front();
		}
		while(!min_dq.empty() and min_dq.front() <= i - m){
			min_dq.pop_front();
		}
		
		while(!max_dq.empty() and arr[i] >= arr[max_dq.back()]){
			max_dq.pop_back();
		}
		while(!min_dq.empty() and arr[i] <= arr[min_dq.back()]){
			min_dq.pop_back();
		}
		
		max_dq.push_back(i);
		min_dq.push_back(i);
		
	}
	
	if(arr[max_dq.front()] - arr[min_dq.front()] <= c){
		cnt++;
		cout << n - m + 1;
	}
	
	if(cnt == 0){
		cout << "NONE";
	}
	
	return 0;
}