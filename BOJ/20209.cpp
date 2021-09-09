#include <iostream>
#include <vector>

using namespace std;

int answer = 987654321;

bool allSame(vector<int>& cube){
	int x = cube.front();
	for(int i = 1; i < cube.size(); i++){
		if(x != cube[i]){
			return false;
		}
	}
	return true;
}

void dfs(vector<int> cube, vector<vector<int>>& switches, int idx, int cnt){
	
	if(allSame(cube)){
		answer = min(answer, cnt);
		return;
	}
	
	if(idx == switches.size()){
		return;
	}
	
	for(int i = 0; i <= 4; i++){
		if(i != 0){
			for(int j = 0; j < switches[idx].size(); j++){
				cube[switches[idx][j]] += idx + 1;
				cube[switches[idx][j]] %= 5;
			}
		}
		dfs(cube, switches, idx + 1, cnt + i);
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	vector<int> cube(n);
	for(int i = 0; i < n; i++){
		cin >> cube[i];
	}
	
	vector<vector<int>> switches(k);
	for(int i = 0; i < k; i++){
		int x;
		cin >> x;
		switches[i].resize(x);
		for(int j = 0; j < x; j++){
			cin >> switches[i][j];
			switches[i][j]--;
		}
	}
	
	dfs(cube, switches, 0, 0);
	
	if(answer == 987654321){
		answer = -1;
	}
	
	cout << answer;
	
	return 0;
}