#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void layer_rotate(vector<vector<int>>& arr, int r1, int c1, int r2, int c2){
	
	int temp = arr[r1][c2];
	for(int i = c2; i > c1; i--){
		arr[r1][i] = arr[r1][i - 1];
	}
	
	int temp2 = temp;
	temp = arr[r2][c2];
	for(int i = r2; i > r1; i--){
		if(i - 1 == r1){
			arr[i][c2] = temp2;
			continue;
		}
		arr[i][c2] = arr[i - 1][c2];
	}

	temp2 = temp;
	temp = arr[r2][c1];
	for(int i = c1; i < c2; i++){
		if(i + 1 == c2){
			arr[r2][i] = temp2;
			continue;
		}
		arr[r2][i] = arr[r2][i + 1];
	}
	
	temp2 = temp;
	
	for(int i = r1; i < r2; i++){
		if(i + 1 == r2){
			arr[i][c1] = temp2;
			continue;
		}
		arr[i][c1] = arr[i + 1][c1];
	}

}

void rotate(vector<vector<int>>& arr, int r, int c, int s){
	
	for(int layer = 0; layer < s; layer++){
		
		int r1 = r - s + layer;
		int r2 = r + s - layer;
		int c1 = c - s + layer;
		int c2 = c + s - layer;
		
		layer_rotate(arr, r1, c1, r2, c2);
			
	}
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<vector<int>> arr(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int  j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	
	vector<vector<int>> rotate_input;
	vector<int> idx(k);
	
	for(int i = 0; i < k; i++){
		idx[i] = i;
		int r, c, s;
		cin >> r >> c >> s;
		rotate_input.push_back({r - 1, c - 1, s});
	}
	
	int answer = 987654321;
	
	do{
		vector<vector<int>> temp(arr);
		for(auto i : idx){
			rotate(temp, rotate_input[i][0], rotate_input[i][1], rotate_input[i][2]);
		}
		for(int i = 0; i < temp.size(); i++){
			int sum = 0;
			for(int j = 0; j < temp[i].size(); j++){
				sum += temp[i][j];
			}
			answer = min(answer, sum);
		}
	}while(next_permutation(idx.begin(), idx.end()));
	
	cout << answer;
	
	return 0;
}