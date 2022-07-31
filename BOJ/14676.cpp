#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<vector<int>> need(n + 1);
	vector<int> need_cnt(n + 1);
	vector<int> cnt(n + 1);
	
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		need[a].push_back(b);
		need_cnt[b]++;
	}
	
	for(int i = 0; i < k; i++){
		int c, a;
		cin >> c >> a;
		if(c == 1){
			if(need_cnt[a]){
				cout << "Lier!";
				return 0;
			}
			if(++cnt[a] == 1){
				for(int j = 0; j < need[a].size(); j++){
					need_cnt[need[a][j]]--;
				}
			}
		}else{
			if(cnt[a] == 0){
				cout << "Lier!";
				return 0;
			}
			if(--cnt[a] == 0){
				for(int j = 0; j < need[a].size(); j++){
					need_cnt[need[a][j]]++;
				}
			}
		}
	}
	
	cout << "King-God-Emperor";
	
	return 0;
}