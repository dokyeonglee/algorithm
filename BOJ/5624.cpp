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
	
	vector<bool> visited(400001, false);
	
	int answer = 0;
	
	for(int i = 0; i < n; i++){
		
		for(int j = 0; j < i; j++){
			if(visited[arr[i] - arr[j] + 200000]){
				answer++;
				break;
			}		
		}
		
		for(int j = 0; j <= i; j++){
			visited[arr[i] + arr[j] + 200000] = true;
		}
	}
	
	cout << answer;
	
	return 0;
}