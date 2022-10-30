#include <iostream>
#include <vector>
#include <algorithm>

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
	
	sort(arr.begin(), arr.end(), greater<int>());

	long long answer = 0;
	for(int i = 0; i < n / 2; i++){
		answer += 2 * arr[i];
	}
	
	for(int i = n / 2; i < n; i++){
		answer -= 2 * arr[i];
	}
	
	if(n % 2 == 0){
		answer -= arr[n / 2 - 1];
		answer += arr[n / 2];
	}else{
		long long temp = answer;
		answer += arr[n / 2];
		answer += arr[n / 2 + 1];
		temp += 3 * arr[n / 2];
		temp -= arr[n / 2 - 1];
		answer = max(answer, temp);
	}
	
	cout << answer;
	
	return 0;
}