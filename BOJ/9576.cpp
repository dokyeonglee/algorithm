#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		
		int n, m;
		cin >> n >> m;
		
		vector<pair<int, int>> arr(m);
		for(int i = 0; i < m; i++){
			cin >> arr[i].second >> arr[i].first;
		}
		
		sort(arr.begin(), arr.end());
		
		vector<bool> visited(1001, false);
		
		int answer = 0;
		
		for(int i = 0; i < m; i++){
			for(int j = arr[i].second; j <= arr[i].first; j++){
				if(!visited[j]){
					visited[j] = true;
					answer++;
					break;
				}
			}
		}
		
		cout << answer << "\n";
		
	}
	
	return 0;
}