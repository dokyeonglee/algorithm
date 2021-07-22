#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> minimum(n);
	for(int i = 0; i < 4; i++){
		cin >> minimum[i];
	}
	
	vector<vector<int>> food(n, vector<int>(4));
	vector<int> price(n);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 4; j++){
			cin >> food[i][j];
		}
		cin >> price[i];
	}
	
	int answer = 987654321;
	map<int, vector<vector<int>>> indices_v;
	
	for(int i = 0; i < (1 << n); i++){
		
		vector<int> sum(4);
		int money = 0;
		vector<int> indices;
		
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				money += price[j];
				indices.push_back(j + 1);
				for(int k = 0; k < 4; k++){
					sum[k] += food[j][k];
				}
			}
		}
		
		bool check = true;
		
		for(int i = 0; i < 4; i++){
			if(sum[i] < minimum[i]){
				check = false;
				break;
			}
		}
		
		if(check){
			if(answer >= money){
				answer = money;
				indices_v[answer].push_back(indices);
			}
		}
		
		
	}
	
	if(answer == 987654321){
		cout << -1;
	}else{
		cout << answer << "\n";
		sort(indices_v[answer].begin(), indices_v[answer].end());
		
		for(int i : indices_v[answer][0]){
			cout << i << " ";
		}
	}
	
	return 0;
}