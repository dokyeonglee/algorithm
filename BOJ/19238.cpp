#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int WALL = -987654321;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

pair<int, int> find_passenger(vector<vector<int>>& map, vector<pair<int, int>>& src, pair<int, int>& taxi, int fuel){
	
	int n = map.size();
	
	queue<pair<pair<int, int>, pair<int, int>>> q;
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	
	q.push(make_pair(make_pair(0, fuel), taxi));
	visited[taxi.first][taxi.second] = true;
	
	pair<int, int> result = make_pair(-1, 987654321);
	
	while(!q.empty()){
		
		int distance = q.front().first.first;
		int remain_fuel = q.front().first.second;
		pair<int, int> now = q.front().second;
		q.pop();
		
		if(map[now.first][now.second] >= 1){
			if(result.second >= distance){
				int passenger_num = map[now.first][now.second];
				if(src[result.first] > src[passenger_num]){
					result.first = passenger_num;
					result.second = distance;
				}
			}
		}
		
		for(int i = 0; i < 4; i++){
			
			int next_r = now.first + dr[i];
			int next_c = now.second + dc[i];
			
			if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= n){
				continue;
			}
			
			if(!visited[next_r][next_c] and map[next_r][next_c] != WALL and remain_fuel > 0){
				visited[next_r][next_c] = true;
				q.push(make_pair(make_pair(distance + 1, remain_fuel - 1), make_pair(next_r, next_c)));
			}
		}
	}
	
	return result;
} 

int bfs(vector<vector<int>>& map, pair<int, int>& taxi, pair<int, int> dst, int fuel){
	
	int n = map.size();
	
	queue<pair<pair<int, int>, pair<int, int>>> q;
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	
	q.push(make_pair(make_pair(0, fuel), taxi));
	visited[taxi.first][taxi.second] = true;
	
	int result = 987654321;
	
	while(!q.empty()){
		
		int distance = q.front().first.first;
		int remain_fuel = q.front().first.second;
		pair<int, int> now = q.front().second;
		q.pop();
		
		if(now == dst){
			taxi = now;
			result = min(result, distance);
		}
		
		for(int i = 0; i < 4; i++){
			
			int next_r = now.first + dr[i];
			int next_c = now.second + dc[i];
			
			if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= n){
				continue;
			}
			
			if(!visited[next_r][next_c] and map[next_r][next_c] != WALL and remain_fuel > 0){
				visited[next_r][next_c] = true;
				q.push(make_pair(make_pair(distance + 1, remain_fuel - 1), make_pair(next_r, next_c)));
			}
		}
	}
	
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, fuel;
	cin >> n >> m >> fuel;
	
	vector<vector<int>> map(n, vector<int>(n));
	vector<pair<int, int>> passenger_src(m + 1);
	vector<pair<int, int>> passenger_dst(m + 1);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			
			cin >> map[i][j];
			
			if(map[i][j] == 1){
				map[i][j] = WALL;
			}
		}
	}
	
	pair<int, int> taxi;
	cin >> taxi.first >> taxi.second;
	taxi.first--;
	taxi.second--;
	
	int r, c;
	
	for(int i = 1; i <= m; i++){
		
		cin >> r >> c;
		map[r - 1][c - 1] = i;
		passenger_src[i] = make_pair(r - 1, c - 1);
		
		cin >> r >> c;
		passenger_dst[i] = make_pair(r - 1, c - 1);
	}
	
	int answer = 0;
	
	for(int i = 0; i < m; i++){

		pair<int, int> p = find_passenger(map, passenger_src, taxi, fuel);	
		if(p.first == -1){
			fuel = -1;
			break;
		}
		
		fuel -= p.second;
		taxi = passenger_src[p.first];
		map[taxi.first][taxi.second] = 0;
		
		int distance = bfs(map, taxi, passenger_dst[p.first], fuel);
		
		if(distance == 987654321){
			fuel = -1;
			break;
		}
		
		fuel += distance;
	}
	
	cout << fuel;
	
	return 0;
}