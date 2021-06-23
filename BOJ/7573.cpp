#include <iostream>
#include <vector>

using namespace std;

int count_fish(vector<pair<int, int>>& fish, int r, int c, int h, int w){
	
	int result = 0;
	
	for(int i = 0; i < fish.size(); i++){
		if(r <= fish[i].first and fish[i].first <= r + h and c <= fish[i].second and fish[i].second <= c + w){
			result++;
		}
	}
	
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, l, m;
	cin >> n >> l >> m;
	
	vector<pair<int, int>> fish(m);
	for(int i = 0; i < m; i++){
		cin >> fish[i].first >> fish[i].second;
	}
	
	int answer = 0;
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			for(int k = 1; k < l / 2; k++){
				answer = max(answer, count_fish(fish, fish[i].first, fish[j].second, k, l / 2 - k));
			}
		}
	}
	
	cout << answer;
	
	return 0;
}