#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<long long> arr(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	
	vector<int> answer(n + 1);
	
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			int cnt = 2;
			for(int k = i + 1; k < j; k++){
				if((arr[j] - arr[i]) * (k - i) > (arr[k] - arr[i]) * (j - i)){
					cnt++;
				}
			}
			if(cnt == j - i + 1){
				answer[i]++;
				answer[j]++;
			}
		}
	}
	
	cout << *max_element(answer.begin(), answer.end());
	
	return 0;
}