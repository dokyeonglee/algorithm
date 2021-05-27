#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0 , -1};

struct Robot{
	int r;
	int c;
	int dir;
};

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b;
	cin >> a >> b;
	
	int n, m;
	cin >> n >> m;
	
	vector<Robot> robot(n + 1);
	vector<vector<int>> map(b + 1, vector<int>(a + 1));
	
	int r, c;
	char dir;
	
	for(int i = 1; i <= n; i++){
		
		cin >> robot[i].c >> robot[i].r >> dir;
		
		if(dir == 'N'){
			robot[i].dir = 0;
		}else if(dir == 'E'){
			robot[i].dir = 1;
		}else if(dir == 'S'){
			robot[i].dir = 2;
		}else if(dir == 'W'){
			robot[i].dir = 3;
		}
		
		map[robot[i].r][robot[i].c] = i;
		
	}
	
	for(int i = 0; i < m; i++){
		
		int robot_no, cnt;
		char command;
		
		cin >> robot_no >> command >> cnt;
		
		if(command == 'L'){
			cnt %= 4;
			robot[robot_no].dir = (robot[robot_no].dir - cnt + 4) % 4;
		}else if(command == 'R'){
			cnt %= 4;
			robot[robot_no].dir = (robot[robot_no].dir + cnt) % 4;
		}else if(command == 'F'){
			
			int dir = robot[robot_no].dir;
			int& r = robot[robot_no].r;
			int& c = robot[robot_no].c;
			
			map[r][c] = 0;
			
			for(int k = 0; k < cnt; k++){
				
				r += dr[dir];
				c += dc[dir];
				
				if(r < 1 or r > b or c < 1 or c > a){
					cout << "Robot " << robot_no << " crashes into the wall\n";
					return 0;
				}else if(map[r][c]){
					cout << "Robot " << robot_no << " crashes into robot " << map[r][c] << "\n";
					return 0;
				}
			}
			
			map[r][c] = robot_no;
			
		}
		
	}
	
	cout << "OK\n";
	
	return 0;
}