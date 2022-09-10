#include <iostream>
#include <queue>
#include <map>

using namespace std;

int dr[] = {-1, -1, 1, 1};
int dc[] = {-1, 1, -1, 1};

map<pair<int, int>, pair<int, int>> path;

bool possible = false;

int dfs(int r, int c, int bit){
	
	if(r == 0 and c == 0){
		possible = true;
		return 0;
	}
	
	if(bit == 0){
		if(abs(r) == 1 and abs(c) == 1){
			possible = true;
			return 1;
		}
		return 987654321;
	}
	
	int next_r;
	int next_c;
	bool check = false;
	for(int i = 0; i < 4; i++){
		next_r = r + (1 << bit) * dr[i];
		next_c = c + (1 << bit) * dc[i];
		if(abs(next_r) <= (1 << bit) and abs(next_c) <= (1 << bit)){
			check = true;
			break;
		}
	}
	
	
	int used = 987654321;
	if(check){
		used = dfs(next_r, next_c, bit - 1) + 1;
	}
	int unused = dfs(r, c, bit - 1);
	
	if(check and used < unused){
		path[make_pair(r, c)] = make_pair(next_r, next_c);
	}
	
	return min(used, unused);
}


int main() {
	
	int r, c;
	cin >> r >> c;
	
	dfs(r, c, 27);
	
	if(!possible){
		cout << -1;
		return 0;
	}
	
	vector<pair<int, int>> answer;
	while(r != 0 and c != 0){
		answer.push_back(make_pair(r, c));
		auto temp = path[make_pair(r, c)];
		r = temp.first;
		c = temp.second;
	}
	answer.push_back(make_pair(0, 0));
	
	cout << answer.size() << "\n";
	for(auto it = answer.rbegin(); it != answer.rend(); it++){
		cout << it->first << ", " << it->second << "\n";
	}
	
	return 0;
}