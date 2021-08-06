#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	vector<vector<int>> arr(n + 1, vector<int>(n + 1));
	

	for(int i = 0; i < k; i++){
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(arr[i][k] and arr[k][j]){
					arr[i][j] = 1;
				}
			}
		}
	}
	
	int s;
	cin >> s;
	
	while(s--){
		int a, b;
		cin >> a >> b;
		if(arr[a][b] == 0 and arr[b][a] == 0){
			cout << "0\n";
		}else if(arr[a][b]){
			cout << "-1\n";
		}else{
			cout << "1\n";
		}
	}
	
	
	return 0;
}