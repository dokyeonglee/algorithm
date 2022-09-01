#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

int sqrt_n;

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
	if(a.second.first / sqrt_n != b.second.first / sqrt_n){
		return a.second.first / sqrt_n < b.second.first / sqrt_n;
	}
	return a.second.second < b.second.second;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	sqrt_n = sqrt(n);
	
	unordered_map<int, int> mp;
	vector<int> arr(n);
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(mp.count(x) == 0){
			mp[x] = mp.size() + 1;
		}
		arr[i] = mp[x];
	}
	
	int m;
	cin >> m;
	
	vector<pair<int, pair<int, int>>> query(m);
	for(int i = 0; i < m; i++){
		int l, r;
		cin >> l >> r;
		query[i] = make_pair(i, make_pair(l - 1, r - 1));
	}
	
	sort(query.begin(), query.end(), compare);
	
	vector<long long> answer(m);
	int s = query[0].second.first;
	int e = query[0].second.second;
	
	vector<int> cnt(1000001);
	int result = 0;
	
	for(int i = s; i <= e; i++){
		if(cnt[arr[i]]++ == 0){
			result++;	
		}
	}
	
	answer[query[0].first] = result;
	
	for(int i = 1; i < m; i++){
		while(s < query[i].second.first){
			if(--cnt[arr[s++]] == 0){
				result--;
			}
		}
		while(s > query[i].second.first){
			if(cnt[arr[--s]]++ == 0){
				result++;	
			}
		}
		
		while(e < query[i].second.second){
			if(cnt[arr[++e]]++ == 0){
				result++;	
			}
		}
		while(e > query[i].second.second){
			if(--cnt[arr[e--]] == 0){
				result--;
			}
		}
		answer[query[i].first] = result;
	}
	
	for(int i = 0; i < m; i++){
		cout << answer[i] << "\n";
	}
	
	
	return 0;
}