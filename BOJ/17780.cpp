#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

void change_direction(vector<pair<int, pair<int, int>>>& pos, string& pieces){
	pos[pieces[0] - 'A'].first ^= 1;
}

void change_pos(vector<pair<int, pair<int, int>>>& pos, pair<int, int> next, string& pieces){
    for(char c : pieces){
        pos[c - 'A'].second = next;
    }
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	vector<vector<int>> arr(n + 5, vector<int>(n + 5, 2));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> arr[i][j];
		}
	}
	
	vector<vector<string>> board(n + 5, vector<string>(n + 5));
	
	int r, c, d;
	
	vector<pair<int, pair<int, int>>> pos(k);
	for(int i = 0; i < k; i++){
		cin >> r >> c >> d;
		pos[i] = make_pair(d - 1, make_pair(r, c));
		board[r][c] += 'A' + i;
	}
    
	for(int turn = 1; turn <= 1000; turn++){
        bool check = false;
		for(int i = 0; i < k; i++){
			d = pos[i].first;
			r = pos[i].second.first;
			c = pos[i].second.second;
			if(board[r][c][0] - 'A' != i){
				continue;
			}
			int next_r = r + dr[d];
			int next_c = c + dc[d];
			if(arr[next_r][next_c] == 2){
                if(!check){
                    change_direction(pos, board[r][c]);
                    i--;
                    check = true;
                }else{
                    check = false;
                }
                continue;
			}else if(arr[next_r][next_c] == 1){
                reverse(board[r][c].begin(), board[r][c].end());
            }
			board[next_r][next_c] += board[r][c];
            board[r][c] = "";
            change_pos(pos, make_pair(next_r, next_c), board[next_r][next_c]);
            if(board[next_r][next_c].size() >= 4){
                cout << turn;
                return 0;
            }
			check = false;
		}
	}

	cout << -1;
	
	return 0;
}