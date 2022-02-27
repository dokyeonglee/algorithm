#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<vector<int>> arr(12, vector<int>(12));
	
	for(int i = 1; i <= 10; i++){
		string str;
		cin >> str;
		for(int j = 0; j < str.size(); j++){
			if(str[j] != '#'){
				arr[i][j + 1] = 1;
			}
		}
	}
	
	int answer = 987654321;
	for(int i = 0; i < 1024; i++){
		vector<vector<int>> temp(arr);
		int cnt = 0;
		for(int j = 0; j < 10; j++){
			if(i & (1 << j)){
				cnt++;
				temp[0][j + 1] ^= 1;
				temp[1][j] ^= 1;
				temp[1][j + 1] ^= 1;
				temp[2][j + 1] ^= 1;
				temp[1][j + 2] ^= 1;
			}
		}
	
		for(int r = 2; r <= 10; r++){
			for(int c = 1; c <= 10; c++){
				if(temp[r - 1][c] == 1){
					cnt++;
					temp[r - 1][c] ^= 1;
					temp[r][c - 1] ^= 1;
					temp[r][c] ^= 1;
					temp[r + 1][c] ^= 1;
					temp[r][c + 1] ^= 1;
				}
			}
		}
		
		bool check = true;
		
		for(int r = 1; r <= 10; r++){
			for(int c = 1; c <= 10; c++){
				if(temp[r][c] == 1){
					check = false;
				}
			}
		}
		
		if(check){
			answer = min(answer, cnt);
		}
		
	}
	
	if(answer == 987654321){
		answer = -1;
	}
	
	cout << answer;
	
	return 0;
}