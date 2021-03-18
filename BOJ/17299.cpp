#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> arr(n);
	vector<int> cnt(1000001);
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	
	stack<int> s;
	vector<int> answer(n);
	
	for(int i = n - 1; i >= 0; i--){
		
		while(!s.empty() and cnt[arr[i]] >= cnt[s.top()]){
			s.pop();
		}
		
		if(s.empty()){
			answer[i] = -1;
		}else{
			answer[i] = s.top();
		}
		
		s.push(arr[i]);
		
	}
	
	for(int i = 0; i < n; i++){
		cout << answer[i] << " ";
	}
	
	return 0;
}