#include <iostream>
#include <vector>

using namespace std;

bool can_pass(vector<int>& road, int l){
	
	vector<bool> installed(road.size(), false);
	
	for(int i = 1; i < road.size(); i++){
		if(abs(road[i] - road[i - 1]) > 1){
			return false;
		}
		if(road[i - 1] < road[i]){
			
			if(i < l){
				return false;	
			}
			
			for(int j = 1; j <= l; j++){
				if(road[i - 1] != road[i - j]){
					return false;
				}
				if(installed[i - j]){
					return false;
				}
				installed[i - j] = true;
			}
			
		}
		if(road[i - 1] > road[i]){
			
			if(i + l > road.size()){
				return false;	
			}
			
			for(int j = 0; j < l; j++){
				if(road[i] != road[i + j]){
					return false;
				}
				if(installed[i + j]){
					return false;
				}
				installed[i + j] = true;
			}	
			
		}
	}
	
	return true;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, l;
	cin >> n >> l;
	
	vector<vector<int>> arr(n, vector<int>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	
	int answer = 0;
	
	for(int i = 0; i < n; i++){
		if(can_pass(arr[i], l)){
			answer++;
		}	
	}
	
	for(int i = 0; i < n; i++){
		vector<int> road(n);
		for(int j = 0; j < n; j++){
			road[j] = arr[j][i];
		}
		if(can_pass(road, l)){
			answer++;
		}
	}
	
	cout << answer;
	
	return 0;
}