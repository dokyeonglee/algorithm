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
	
	vector<bool> visited(1 << 17, false);
	
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(visited[arr[i] ^ arr[j]]){
				cout << "Yes";
				return 0;
			}
			visited[arr[i] ^ arr[j]] = true;
		}
	}
	
	cout << "No";
	
	return 0;
}