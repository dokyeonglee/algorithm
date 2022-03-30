#include <iostream>
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
	
	double avg = 1e18;
	int answer = -1;
	
	for(int i = 0; i < n - 1; i++){
		if(avg > (arr[i] + arr[i + 1]) / 2.0){
			avg = (arr[i] + arr[i + 1]) / 2.0;
			answer = i;
		}
	}
	
	for(int i = 0; i < n - 2; i++){
		if(avg >= (arr[i] + arr[i + 1] + arr[i + 2]) / 3.0){
			avg = (arr[i] + arr[i + 1] + arr[i + 2]) / 3.0;
			answer = min(answer, i);
		}
	}
	
	cout << answer;
	
	return 0;
}