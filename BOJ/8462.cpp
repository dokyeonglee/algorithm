#include <iostream>
#include <vector>
#include <algorithm>
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
	
	int n, t;
	cin >> n >> t;
	
	sqrt_n = sqrt(n);
	
	vector<long long> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	vector<pair<int, pair<int, int>>> query(t);
	for(int i = 0; i < t; i++){
		int l, r;
		cin >> l >> r;
		query[i] = make_pair(i, make_pair(l - 1, r - 1));
	}
	
	sort(query.begin(), query.end(), compare);
	
	vector<long long> answer(t);
	int s = query[0].second.first;
	int e = query[0].second.second;
	
	vector<long long> cnt(1000001);
	long long result = 0;
	
	for(int i = s; i <= e; i++){
		result += (2 * cnt[arr[i]]++ + 1) * arr[i];
	}
	
	answer[query[0].first] = result;
	
	for(int i = 1; i < t; i++){
		while(s < query[i].second.first){
			result -= (2 * cnt[arr[s]]-- - 1) * arr[s++];
		}
		while(s > query[i].second.first){
			result += (2 * cnt[arr[--s]]++ + 1) * arr[s];
		}
		
		while(e < query[i].second.second){
			result += (2 * cnt[arr[++e]]++ + 1) * arr[e];
		}
		while(e > query[i].second.second){
			result -= (2 * cnt[arr[e]]-- - 1) * arr[e--];
		}
		answer[query[i].first] = result;
	}
	
	for(int i = 0; i < t; i++){
		cout << answer[i] << "\n";
	}
	
	
	return 0;
}