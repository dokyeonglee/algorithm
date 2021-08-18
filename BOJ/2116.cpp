#include <iostream>
#include <vector>

using namespace std;

int opposite[6] = {5, 3, 4, 1, 2, 0};

int max(vector<int>& dice, int idx){
	int result = 0;
	for(int i = 1; i <= 6; i++){
		if(i != dice[idx] and i != dice[opposite[idx]]){
			result = max(result, i);
		}
	}
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> dice(n, vector<int>(6));
	for(int i = 0 ; i < n; i++){
		for(int j = 0; j < 6; j++){
			cin >> dice[i][j];
		}
	}
	
	int answer = 0;
	
	for(int i = 0; i < 6; i++){
		int now = dice[0][i];
		int sum = max(dice[0], i);
		for(int j = 1; j < n; j++){
			for(int k = 0; k < 6; k++){
				if(dice[j][k] == now){
					now = dice[j][opposite[k]];
					sum += max(dice[j], k);
					break;
				}
			}
		}
		answer = max(answer, sum);
	}
	
	cout << answer;
	
	return 0;

}