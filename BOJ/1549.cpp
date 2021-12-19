#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<long long> arr(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	
	long long answer = 987654321;
	int length = -1;
	
	for(int k = 1; k <= n / 2; k++){
		for(int i = 1; i <= n; i++){
			for(int j = i + k; j + k <= n + 1; j++){
				long long diff = abs(arr[j + k - 1] - arr[j - 1] - (arr[i + k - 1] - arr[i - 1]));
				if(diff <= answer){
					answer = diff;
					length = max(length, k);
				}
			}
		}
	}
	
	cout << length << "\n" << answer;
	
	return 0;
}