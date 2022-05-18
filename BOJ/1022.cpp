#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};

int main() {
		
	vector<vector<int>> arr(50, vector<int>(5));
	
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	
	int r = 0;
	int c = 0;
	int dir = 0;
	int num = 1;
	int cnt = 0;
	int curr_line_cnt = 0;
	int cnt_per_line = 1;
	int max_num = 0;
	
	while(true){
		if(r1 <= r and r <= r2 and c1 <= c and c <= c2){
			arr[r - r1][c - c1] = num;
			cnt++;
			max_num = max(max_num, num);
			if(cnt == (r2 - r1 + 1) * (c2 - c1 + 1)){
				break;	
			}
		}
		r += dr[dir];
		c += dc[dir];
		num++;
		curr_line_cnt++;
		if(curr_line_cnt == cnt_per_line){
			curr_line_cnt = 0;
			dir = (dir + 1) % 4;
			if(dir == 0 or dir == 2){
				cnt_per_line++;
			}
			
		}
	}
	
	cnt = 0;
	while(max_num > 0){
		cnt++;
		max_num /= 10;
	}
	
	for(int i = 0; i <= r2 - r1; i++){
		for(int j = 0; j <= c2 - c1; j++){
			printf("%*d ", cnt, arr[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}