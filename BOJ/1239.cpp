#include <iostream>
#include <algorithm>
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
	
	sort(arr.begin(), arr.end());
	
	int answer = 0;
	
	do{
		int result = 0;
		for(int i = 0; i < n; i++){
			int sum = 0;
			int idx = i;
			while(sum < 50){
				sum += arr[idx];
				idx = (idx + 1) % n;
			}
			result += (sum == 50);
		}
		answer = max(answer, result);
	}while(next_permutation(arr.begin(), arr.end()));
	
	cout << answer / 2;
	
	return 0;
}