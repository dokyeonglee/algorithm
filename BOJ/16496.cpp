#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
	return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	sort(arr.begin(), arr.end(), compare);
	
	string answer = "";
	for(int i = 0; i < n; i++){
		if(answer.compare("0") != 0){
			answer += to_string(arr[i]);
		}
	}
	
	cout << answer;
	
	return 0;
}