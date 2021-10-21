#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<long long> arr(n);
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		for(int j = 0; j < str.size(); j++){
			arr[i] = (arr[i] << 1) | (str[j] - '0');
		}
	}
	
	int k;
	cin >> k;
	
	int answer = 0;
	for(int i = 0; i < n; i++){
		int cnt = m - __builtin_popcountll(arr[i]);
		int result = 0;
		if(cnt <= k and cnt % 2 == k % 2){
			for(int j = 0; j < n; j++){
				if(arr[i] == arr[j]){
					result++;
				}
			}			
		}
		answer = max(answer, result);
	}
	
	cout << answer;
	
	return 0;
}