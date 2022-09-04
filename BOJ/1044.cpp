#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<long long> score1(n);
	vector<long long> score2(n);
	
	for(int i = n - 1; i >= 0; i--){
		cin >> score1[i];
	}
	
	for(int i = n - 1; i >= 0; i--){
		cin >> score2[i];
	}
	
	map<int, vector<pair<long long, long long>>> m;
	set<pair<long long, long long>> s;
	
	for(long long i = 0; i < (1ll << (n / 2)); i++){
		long long team1 = 0;
		long long team2 = 0;
		int cnt = 0;
		for(long long j = 0; j < n / 2; j++){
			if((i & (1ll << j)) == 0){
				team1 += score1[j];
				cnt++;
			}else{
				team2 += score2[j];
				cnt--;
			}
		}
		
		if(s.count(make_pair(cnt, team1 - team2)) == 0){
			m[cnt].push_back(make_pair(team1 - team2, i));
		}
		
		s.insert(make_pair(cnt, team1 - team2));
	}
		
	for(auto& it : m){
		sort(it.second.begin(), it.second.end());
	}

	long long result = 1e18;
	long long min_diff = 1e18;
	
	for(long long i = 0; i < (1ll << n); i += (1ll << (n / 2))){
		long long team1 = 0;
		long long team2 = 0;
		int cnt = 0;
		for(long long j = n / 2; j < n; j++){
			if((i & (1ll << j)) == 0){
				team1 += score1[j];
				cnt++;
			}else{
				team2 += score2[j];
				cnt--;
			}
		}
	
		auto it = lower_bound(m[-cnt].begin(), m[-cnt].end(), make_pair(team2 - team1, -1ll));
		if(it != m[-cnt].end()){
			if(abs(it->first + team1 - team2) < min_diff){
				min_diff = abs(it->first + team1 - team2);
				result = it->second | i;
			}else if(min_diff == abs(it->first + team1 - team2)){
				result = min(result, it->second | i);
			}
		}
		if(it != m[-cnt].begin()){
			it--;
			if(abs(it->first + team1 - team2) < min_diff){
				min_diff = abs(it->first + team1 - team2);
				result = it->second | i;
			}else if(min_diff == abs(it->first + team1 - team2)){
				result = min(result, it->second | i);
			}
		}
		
	}
	
	vector<int> answer(n);
	
	for(int i = n - 1; i >= 0; i--){
		if((result & (1ll << i)) == 0){
			answer[i] = 1;
		}else{
			answer[i] = 2;
		}
	}
	
	for(int i = n - 1; i >= 0; i--){
		cout << answer[i] << " ";
	}
	
	return 0;
}