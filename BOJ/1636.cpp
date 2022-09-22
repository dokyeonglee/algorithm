#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<int, int>> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i].first >> arr[i].second;
	}
	
	int min_sum = 987654321;
	int curr = 0;
	vector<int> answer;
	
	for(int i = arr[0].first; i <= arr[0].second; i++){
		int _curr = i;
		int sum = 0;
		for(int j = 1; j < n; j++){
			int s = arr[j].first;
			int e = arr[j].second;
			if(_curr < s){
				sum += s - _curr;
				_curr = s;
			}else if(e < _curr){
				sum += _curr - e;
				_curr = e;
			}
		}
		if(sum < min_sum){
			min_sum = sum;
			curr = i;
		}
	}
	
	cout << min_sum << "\n";
	
	answer.push_back(curr);
	for(int j = 1; j < n; j++){
		int s = arr[j].first;
		int e = arr[j].second;
		if(curr < s){
			curr = s;
		}else if(e < curr){
			curr = e;
		}
		answer.push_back(curr);
	}
	
	
	for(int i = 0; i < n; i++){
		cout << answer[i] << "\n";
	}
	
	return 0;
}