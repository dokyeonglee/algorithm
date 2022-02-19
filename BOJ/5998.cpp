#include <iostream>
#include <vector>
#include <map>

using namespace std;

void toggle(vector<vector<int>>& arr, long long& light, int now){
	light ^= (1ll << now);
	for(int next : arr[now]){
		light ^= (1ll << next);
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> arr(n);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		arr[u - 1].push_back(v - 1);
		arr[v - 1].push_back(u - 1);
	}
	
	map<long long, long long> cnt;
	
	for(long long i = 1; i < (1ll << (n / 2)); i++){
		long long light = 0;
		for(int j = 0; j < n; j++){
			if(i & (1ll << j)){
				toggle(arr, light, j);
			}
		}
		if(cnt.count(light)){
			cnt[light] = min(cnt[light], (long long)__builtin_popcountll(i));
		}else{
			cnt[light] = __builtin_popcountll(i);
		}
	}
	
	long long answer = 987654321;
	if(cnt.count((1ll << n) - 1)){
		answer = cnt[(1ll << n) - 1];
	}
	
	for(long long i = (1ll << (n / 2)); i < (1ll << n); i += (1 << (n / 2))){
		long long light = 0;
		for(int j = n / 2; j < n; j++){
			long long visited = 0;
			if(i & (1ll << j)){
				toggle(arr, light, j);
			}
		}
		if(light == (1ll << n) - 1){
			answer = min(answer, (long long)__builtin_popcountll(i));
		}else if(cnt.count(light ^ ((1ll << n) - 1))){
			answer = min(answer, cnt[light ^ ((1ll << n) - 1)] + __builtin_popcountll(i));
		}
	}
	
	cout << answer;
	
	return 0;
}