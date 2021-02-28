#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, l;
	cin >> n >> l;
	
	vector<int> arr(n);
	deque<pair<int, int>> dq;
	
	for(int i = 0; i < n; i++){
		
		cin >> arr[i];
		
		if(!dq.empty() and dq.front().second <= i - l){
			dq.pop_front();
		}
		
		while(!dq.empty() and dq.back().first > arr[i]){
			dq.pop_back();
		}
		
		dq.push_back(make_pair(arr[i], i));
		cout << dq.front().first << " ";
		
	}
	
	
	return 0;
}