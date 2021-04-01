#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	vector<char> fold(1 << n);
	
	int start_row = 0;
	int end_row = (1 << n) - 1;
	int start_col = 0;
	int end_col = (1 << n) - 1;
	
	for(int i = 0; i < 2 * n; i++){
		cin >> fold[i];
		if(fold[i] == 'L'){
			end_col = (start_col + end_col) / 2;
		}else if(fold[i] == 'R'){
			start_col = (start_col + end_col) / 2 + 1;
		}else if(fold[i] == 'U'){
			end_row = (start_row + end_row) / 2;
		}else if(fold[i] == 'D'){
			start_row = (start_row + end_row) / 2 + 1;
		}
	}
	
	int pos;
	cin >> pos;
	
	for(int i = 0; i < (1 << n); i++){
		for(int j = 0; j < (1 << n); j++){
			int temp = pos ^ (abs(start_row - i) % 2 * 2) ^ (abs(start_col - j) % 2);
			cout << temp << " ";
		}
		cout << '\n';
	}
	
	return 0;
}