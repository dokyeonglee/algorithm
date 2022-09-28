#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while(1){
		
		int n;
		cin >> n;
		
		if(n == 0){
			break;
		}
		
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		
		unordered_map<long long, vector<pair<int, int>>> umap;
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				umap[arr[i] + arr[j]].push_back(make_pair(i, j));
			}
		}
		
		int answer = -1987654321;
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i == j) continue;
				int x = min(5, (int)umap[arr[i] - arr[j]].size());
				for(int k = 0; k < x; k++){
					if(umap[arr[i] - arr[j]][k].first != i and umap[arr[i] - arr[j]][k].first != j
					and umap[arr[i] - arr[j]][k].second != j and umap[arr[i] - arr[j]][k].second != i){
						answer = max(answer, arr[i]);
					}
				}
			}
		}
		
		if(answer == -1987654321){
			cout << "no solution\n";
		}else{
			cout << answer << "\n";
		}
		
	}
	
	return 0;
}