#include <iostream>
#include <vector>

using namespace std;

void draw(vector<vector<char>>& arr, int row, int col){
	
	arr[row][col] = '*';
	arr[row + 1][col - 1] = '*';
	arr[row + 1][col + 1] = '*';
	
	for(int i = 0; i < 5; i++){
		arr[row + 2][col - 2 + i] = '*';
	}
}

void draw_star(vector<vector<char>>& arr, int row, int col, int length){
	
	if(length == 3){
		draw(arr, row, col);
		return;
	}
	
	length /= 2;
	
	draw_star(arr, row, col, length);
	draw_star(arr, row + length, col - length, length);
	draw_star(arr, row + length, col + length, length);
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<char>> arr(n, vector<char>(2 * n, ' '));
	draw_star(arr, 0, n - 1, n);
	
	for(int i = 0; i < arr.size(); i++){
		for(int j = 0; j < arr[i].size(); j++){
			cout << arr[i][j];
		}
		cout << "\n";
	}
	
	return 0;
}