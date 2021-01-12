#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	int k;
	cin >> k;
	
	deque<int> dq;
	for(int i = 0; i < k; i++){
		int asc, dec;
		cin >> asc >> dec;
		dec = -dec;
		
		while(!dq.empty() and abs(dq.back()) <= asc){
			dq.pop_back();
		}
		dq.push_back(asc);
		
		while(!dq.empty() and abs(dq.back()) <= -dec){
			dq.pop_back();
		}
		dq.push_back(dec);
	}

	vector<int> temp(arr.begin(), arr.begin() + abs(dq.front()));
	sort(temp.begin(), temp.end());

	int asc_idx = abs(dq.front()) - 1;
	int dec_idx = 0;
	int sort_idx = abs(dq.front()) - 1;
	
	dq.push_back(0);
	
	while(dq.front() != 0){
	
		int curr_idx = dq.front();
		dq.pop_front();
		int next_idx = dq.front(); 
		
		if(curr_idx > 0){
			for(int i = 0; i < abs(curr_idx) - abs(next_idx); i++){
				arr[sort_idx--] = temp[asc_idx--];
			}	
		}else{
			for(int i = 0; i < abs(curr_idx) - abs(next_idx); i++){
				arr[sort_idx--] = temp[dec_idx++];
			}
		}
	}	
	
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;

}
