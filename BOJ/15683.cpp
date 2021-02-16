#include <iostream>
#include <vector>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void watch(vector<vector<int>>& office, int r, int c, int dir){
	
	int R = office.size();
	int C = office[0].size();
	
	while(1){
		
		r += dr[dir];
		c += dc[dir];
		
		if(r < 0 or r >= R or c < 0 or c >= C or office[r][c] == 6){
			break;	
		}
		
		if(office[r][c] != 0){
			continue;
		}
		
		office[r][c] = 7;
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> office(n, vector<int>(m));
	vector<pair<int, pair<int, int>>> cctv;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> office[i][j];
			if(office[i][j] >= 1 and office[i][j] <= 5){
				cctv.push_back(make_pair(office[i][j], make_pair(i, j)));	
			}
		}
	}
	
	int answer = 987654321;;
	
	for(int dir = 0; dir < (1 << (2 * cctv.size())); dir++){
		
		vector<vector<int>> office2(office);
		
		int temp = dir;
		for(int i = 0; i < cctv.size(); i++){
			
			int type = cctv[i].first;
			int r = cctv[i].second.first;
			int c = cctv[i].second.second;
			
			int curr_dir = temp % 4;
			temp /= 4;
			
			switch(type){
				case 1:
					watch(office2, r, c, curr_dir);
					break;
				case 2:
					watch(office2, r, c, curr_dir);
					watch(office2, r, c, (curr_dir + 2) % 4);
					break;
				case 3:
					watch(office2, r, c, curr_dir);
					watch(office2, r, c, (curr_dir + 1) % 4);
					break;
				case 4:
					watch(office2, r, c, curr_dir);
					watch(office2, r, c, (curr_dir + 1) % 4);
					watch(office2, r, c, (curr_dir + 2) % 4);
					break;
				case 5:
					watch(office2, r, c, curr_dir);
					watch(office2, r, c, (curr_dir + 1) % 4);
					watch(office2, r, c, (curr_dir + 2) % 4);
					watch(office2, r, c, (curr_dir + 3) % 4);
					break;
			}
		}
		
		int cnt = 0;
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(office2[i][j] == 0){
					cnt++;
				}
			}
		}
		
		answer = min(answer, cnt);
		
	}
	
	cout << answer;
	
	return 0;
}