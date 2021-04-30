#include <iostream>
#include <vector>

using namespace std;

void print_sudoku(vector<vector<int>>& sudoku){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cout << sudoku[i][j];
		}
		cout << endl;
	}
}

void solve_sudoku(vector<vector<int>>& sudoku, vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<bool>>& square, int cnt){
	
	if(cnt == 81){
		print_sudoku(sudoku);
		exit(0);
	}	
	
	int r = cnt / 9;
	int c = cnt % 9;
	
	if(sudoku[r][c] == 0){
		for(int i = 1; i <= 9; i++){
			if(row[r][i] == false and col[c][i] == false and square[r / 3 * 3 + c / 3][i] == false){
				row[r][i] = true;
				col[c][i] = true;
				square[r / 3 * 3 + c / 3][i] = true;
				sudoku[r][c] = i;
				solve_sudoku(sudoku, row, col, square, cnt + 1);
				row[r][i] = false;
				col[c][i] = false;
				square[r / 3 * 3 + c / 3][i] = false;
				sudoku[r][c] = 0;
			}
		}
	}else{
		solve_sudoku(sudoku, row, col, square, cnt + 1);
	}
}

void input_sudoku(vector<vector<int>>& sudoku, vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<bool>>& square){
	for(int i = 0; i < 9; i++){
		string str;
		cin >> str;
		for(int j = 0; j < 9; j++){
			sudoku[i][j] = str[j] - '0';
			if(sudoku[i][j] != 0){
				row[i][sudoku[i][j]] = true;
				col[j][sudoku[i][j]] = true;
				square[i / 3 * 3 + j / 3][sudoku[i][j]] = true;
			}
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<vector<int>> sudoku(9, vector<int>(9));
	vector<vector<bool>> row(9, vector<bool>(9, false));
	vector<vector<bool>> col(9, vector<bool>(9, false));
	vector<vector<bool>> square(9, vector<bool>(9, false));
	
	input_sudoku(sudoku, row, col, square);
	solve_sudoku(sudoku, row, col, square, 0);
	
	return 0;
}