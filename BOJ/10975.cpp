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
	vector<int> brr(arr);
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		brr[i] = arr[i];
	}
	
	sort(brr.begin(), brr.end());
	
	int answer = 0;
	
	for(int i = 0; i < n; i++){
		int j;
		for(j = 0; j < n; j++){
			if(arr[i] == brr[j]){
				brr[j] = 987654321;
				break;
			}
		}
		if(j == 0){
			if(brr[j + 1] != 987654321){
				answer++;
			}
		}else if(j == n - 1){
			if(brr[j - 1] != 987654321){
				answer++;
			}
		}else if(brr[j - 1] != 987654321 and brr[j + 1] != 987654321){
			answer++;
		}
	}
	
	cout << answer;
	
	return 0;
}