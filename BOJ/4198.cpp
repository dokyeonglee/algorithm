#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	vector<int> arr(n);
	vector<int> lis(n, 1);
	vector<int> lds(n, 1);

	int answer = 0;
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	for(int i = n - 1; i >= 0; i--){
		
		for(int j = i + 1; j < n; j++){
			if(arr[i] < arr[j]){
				lis[i] = max(lis[i], lis[j] + 1);
			}
			if(arr[i] > arr[j]){
				lds[i] = max(lds[i], lds[j] + 1);
			}
		}
		
		answer = max(answer, lis[i] + lds[i] - 1);	
	}

	cout << answer;
	
	return 0;
}