#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> arr(n + 2);
	vector<int> indice(n + 2);
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		indice[arr[i]] = i;
	}
	
	int answer = 0;
	for(int i = n; i > 1; i--){
		int idx = indice[i];
		answer += arr[idx] - max(arr[idx + 1], arr[idx - 1]);
		arr.erase(arr.begin() + idx);
		for(int j = 1; j <= n; j++){
			if(indice[j] > idx){
				indice[j]--;
			}
		}
	}
	
	cout << answer;
	
	return 0;
}