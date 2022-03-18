#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> arr(n);
	vector<int> cnt(1000001);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	
	for(int i = 0; i < n; i++){
		long long answer = 0;
		for(int j = 1; j * j <= arr[i]; j++){
			if(arr[i] % j == 0){
				answer += cnt[j];
				if(j * j != arr[i]){
					answer += cnt[arr[i] / j];
				}
			}
		}
		cout << answer - 1 << "\n";
	}
	
	return 0;
}