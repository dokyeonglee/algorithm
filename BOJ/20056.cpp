#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct FireBall{
	int r;
	int c;
	int mass;
	int speed;
	int direction;
};

void move(FireBall& fire_ball, int N){
	int temp_speed = fire_ball.speed % N;
	fire_ball.r = (fire_ball.r + dr[fire_ball.direction] * temp_speed + N) % N;
	fire_ball.c = (fire_ball.c + dc[fire_ball.direction] * temp_speed + N) % N;
}

void move_fire_ball(vector<vector<vector<FireBall>>>& g){
	
	int N = g.size();
	
	vector<vector<vector<FireBall>>> temp(N, vector<vector<FireBall>>(N));
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			for(FireBall& f : g[i][j]){
				move(f, N);
				temp[f.r][f.c].push_back(f);
			}
		}
	}
	
	g = temp;
	
}

void merge_fire_ball(vector<vector<vector<FireBall>>>& g){
	
	int N = g.size();
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(g[i][j].size() > 1){
				
				int number_of_fire_ball = g[i][j].size();
				int new_mass = 0;
				int new_speed = 0;
				
				int check = 0;
				
				for(FireBall& f : g[i][j]){
					new_mass += f.mass;
					new_speed += f.speed;
					if(f.direction % 2 == 0){
						check++;
					}else{
						check--;
					}
				}
				
				new_mass /= 5;
				new_speed /= number_of_fire_ball;
				check = abs(check) != number_of_fire_ball;
				
				g[i][j].clear();
				
				if(new_mass == 0){
					continue;
				}
				
				for(int k = 0; k < 4; k++){
					g[i][j].push_back({i, j, new_mass, new_speed, k * 2 + check});
				}
				
			}
		}
	}
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M, K;
	cin >> N >> M >> K;
	
	vector<vector<vector<FireBall>>> g(N, vector<vector<FireBall>>(N));
	for(int i = 0; i < M; i++){
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		g[r - 1][c - 1].push_back({r - 1, c - 1, m, s, d});
	}
	
	for(int i = 0; i < K; i++){
		move_fire_ball(g);
		merge_fire_ball(g);
	}
	
	int answer = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			for(FireBall f : g[i][j]){
				answer += f.mass;
			}
		}
	}
	
	cout << answer;
	
	return 0;
}