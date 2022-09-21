#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int n, m;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	vector<vector<int>> arr(n + 5, vector<int>(n + 5));
    vector<vector<pair<int, int>>> pos(n / 2 + 5);
    vector<vector<int>> indices(n + 5, vector<int>(n + 5));

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> arr[i][j];
		}
	}

    for(int layer = 1; layer <= n / 2; layer++){
        for(int i = layer; i <= n - layer + 1; i++){
            indices[layer][i] = pos[layer].size();
            pos[layer].push_back(make_pair(layer, i));
        }
        for(int i = layer + 1; i <= n - layer + 1; i++){
            indices[i][n - layer + 1] = pos[layer].size();
            pos[layer].push_back(make_pair(i, n - layer + 1));
        }
        for(int i = n - layer; i >= layer; i--){
            indices[n - layer + 1][i] = pos[layer].size();
            pos[layer].push_back(make_pair(n - layer + 1, i));
        }
        for(int i = n - layer; i >= layer + 1; i--){
            indices[i][layer] = pos[layer].size();
            pos[layer].push_back(make_pair(i, layer));
        }
    }

	vector<long long> rotate_cnt(n / 2 + 5);

	for(int i = 0; i < m; i++){
		int c, x, y;
		cin >> c >> x >> y;
		int layer = min(min(x, y), n + 1 - max(x, y));
		if(c == 1){
			rotate_cnt[x] += y;
			rotate_cnt[x] %= pos[x].size();
		}else if(c == 2){

            auto temp_pos = pos[layer][(indices[x][y] - rotate_cnt[layer] + pos[layer].size()) % pos[layer].size()];
            auto& temp = arr[temp_pos.first][temp_pos.second];

            layer = min(min(x + 1, y), n + 1 - max(x + 1, y));
            temp_pos = pos[layer][(indices[x + 1][y] - rotate_cnt[layer] + pos[layer].size()) % pos[layer].size()];
            auto& temp3 = arr[temp_pos.first][temp_pos.second];

            layer = min(min(x, y + 1), n + 1 - max(x, y + 1));
            temp_pos = pos[layer][(indices[x][y + 1] - rotate_cnt[layer] + pos[layer].size()) % pos[layer].size()];
            auto& temp2 = arr[temp_pos.first][temp_pos.second];

            layer = min(min(x + 1, y + 1), n + 1 - max(x + 1, y + 1));
            temp_pos = pos[layer][(indices[x + 1][y + 1] - rotate_cnt[layer] + pos[layer].size()) % pos[layer].size()];
            auto& temp4 = arr[temp_pos.first][temp_pos.second];

            int ttemp = temp;
            temp = temp3;
            temp3 = temp4;
            temp4 = temp2;
            temp2 = ttemp;

		}else if(c == 3){
            auto temp_pos = pos[layer][(indices[x][y] - rotate_cnt[layer] + pos[layer].size()) % pos[layer].size()];
			cout << arr[temp_pos.first][temp_pos.second] << "\n";
		}
	}
	
	return 0;
}