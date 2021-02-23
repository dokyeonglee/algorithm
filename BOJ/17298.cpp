#include <iostream>
#include <stack>
#include <vector>

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
	
	stack<int> s;
	vector<int> answer(n, -1);
	
	for(int i = 0; i < n; i++){
		while(!s.empty() and arr[s.top()] < arr[i]){
			answer[s.top()] = arr[i];
			s.pop();
		}
		s.push(i);
	}
	
	for(int i = 0; i < n; i++){
		cout << answer[i] << " ";
	}
	
	return 0;
}