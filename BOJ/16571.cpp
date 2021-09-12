#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>> arr, int turn){
	
	bool check = false;
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(arr[i][j] != (3 ^ turn)){
				break;
			}
			if(j == 2){
				check = true;
			}
		}
	}
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(arr[j][i] != (3 ^ turn)){
				break;
			}
			if(j == 2){
				check = true;
			}
		}
	}
	
	for(int i = 0; i < 3; i++){
		if(arr[i][i] != (3 ^ turn)){
			break;
		}
		if(i == 2){
			check = true;
		}
	}
	
	for(int i = 0; i < 3; i++){
		if(arr[i][2 - i] != (3 ^ turn)){
			break;
		}
		if(i == 2){
			check = true;
		}
	}
	
	if(check){
		return -1;
	}
	
	int result = 2;
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(arr[i][j] == 0){
				arr[i][j] = turn;
				result = min(result, dfs(arr, 3 ^ turn));
				arr[i][j] = 0;
			}
		}
	}
	
	if(result == 0 or result == 2){
		return 0;
	}
	
	return -result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<vector<int>> arr(3, vector<int>(3));
	int cnt = 0;
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cin >> arr[i][j];	
			if(arr[i][j] != 0){
				cnt++;
			}
		}
	}
	
	int turn;
	if(cnt % 2 == 0){
		turn = 1;
	}else{
		turn = 2;
	}
	
	int answer = dfs(arr, turn);

	if(answer == 0){
		cout << "D";
	}else if(answer == 1){
		cout << "W";
	}else{
		cout << "L";
	}
	
	return 0;
}