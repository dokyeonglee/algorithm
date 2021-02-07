#include <iostream>
#include <vector>

using namespace std;

const int up = 1;
const int down = 2;
const int right = 3;
const int left = 4;

int dr[] = {0, -1, 1, 0, 0};
int dc[] = {0, 0, 0, 1, -1};

struct Shark{
	int r;
	int c;
	int speed;
	int direction;
	int size;
};

void move_shark(vector<vector<int>>& g, vector<Shark>& sharks, int R, int C){
	
	int r, c, speed, direction, size;
	
	for(int i = 1; i <= sharks.size() - 1; i++){

		if(sharks[i].r == 0){
			continue;
		}

		r = sharks[i].r;
		c = sharks[i].c;
		speed = sharks[i].speed;
		direction = sharks[i].direction;
		size = sharks[i].size;
		
		if(g[r][c] == i){
			g[r][c] = 0;
		}
		
		int turn1[] = {0, r - 1, R - r, C - c, c - 1};
		int turn2[] = {0, r + R - 2, 2 * R - r - 1, 2 * C - c - 1, c + C - 2};
		int turn1_r[] = {0, 1, R, r, r};
		int turn1_c[] = {0, c, c, C, 1};
		int turn2_r[] = {0, R, 1, r, r};
		int turn2_c[] = {0, c, c, 1, C};
		int direction_toggle[] = {0, 3, 3, 7, 7};

		if(speed <= turn1[direction]){
		}else if(speed <= turn2[direction]){
			speed -= turn1[direction];
			r = turn1_r[direction];
			c = turn1_c[direction];
			direction ^= direction_toggle[direction];
		}else{
			speed -= turn2[direction];
			r = turn2_r[direction];
			c = turn2_c[direction];
		}

		r += speed * dr[direction];
		c += speed * dc[direction];
	
		sharks[i].r = r;
		sharks[i].c = c;
		sharks[i].direction = direction;		

		if(g[r][c] < i){
			if(size < sharks[g[r][c]].size){
				sharks[i] = {0};
			}else{
				sharks[g[r][c]] = {0};
				g[r][c] = i;
			}			
		}else{
			g[r][c] = i;
		}
	}
}

int catch_shark(vector<vector<int>>& g, vector<Shark>& sharks, int pos){
	for(int i = 1; i <= g.size() - 1; i++){
		if(g[i][pos] > 0){
			int shark_num = g[i][pos];
			int shark_size = sharks[shark_num].size;
			g[i][pos] = 0;
			sharks[shark_num] = {0};
			return shark_size;
		}
	}	
	return 0;
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int R, C, m;
	cin >> R >> C >> m;
	
	vector<vector<int>> g(R + 2, vector<int>(C + 2)); 
	
	vector<Shark> sharks(m + 1);

	for(int i = 1; i <= m; i++){
		cin >> sharks[i].r >> sharks[i].c >> sharks[i].speed >> sharks[i].direction >> sharks[i].size;
		if(sharks[i].direction <= 2){
			sharks[i].speed %= 2 * (R - 1);
		}else{
			sharks[i].speed %= 2 * (C - 1);
		}
		g[sharks[i].r][sharks[i].c] = i;
	}
	
	int answer = 0;

	for(int i = 1; i <= C; i++){
		answer += catch_shark(g, sharks, i);
		move_shark(g, sharks, R, C);
	}

	cout << answer;
}