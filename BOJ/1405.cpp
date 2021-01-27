#include <cstring>
#include <iostream>

using namespace std;

double answer = 0;

//read question carefully
int dr[] = {0, 0, 1, -1};//EWSN
int dc[] = {1, -1, 0, 0};

int n;
double dir_probability[4];
bool visited[30][30];

void dfs(int r, int c, int depth, double probability){
	
	if(depth == n){
		answer += probability;
		return;
	}
	
	visited[r][c] = true;
	
	for(int i = 0; i < 4; i++){
		
		int next_r = r + dr[i];
		int next_c = c + dc[i];
		
		if(visited[next_r][next_c]){
			continue;
		}else{
			dfs(next_r, next_c, depth + 1, probability * dir_probability[i]);
		}
		
	}
	
	visited[r][c] = false;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	memset(visited, false, sizeof(visited));
	
	cin >> n;
	
	for(int i = 0; i < 4; i++){
		cin >> dir_probability[i];
		dir_probability[i] /= 100.0;
	}
	
	dfs(15, 15, 0, 1);
	
	cout.setf(ios::fixed);
	cout.precision(9);
	cout << answer << endl;
	
	return 0;
}