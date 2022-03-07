#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double distance(pair<long long, long long> x){
	return sqrt(x.first * x.first + x.second * x.second);
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	cout << fixed;
	cout.precision(7);
	
	while(T--){
		
		int n;
		cin >> n;
		
		vector<pair<long long, long long>> p(n);
		for(int i = 0; i < n; i++){
			cin >> p[i].first >> p[i].second;
		}
		
		double answer = 1e18;
		
		for(int i = 0; i < (1 << n); i++){
			if(__builtin_popcount(i) != n / 2){
				continue;
			}
			pair<long long, long long> v = {0, 0};
			for(int j = 0; j < n; j++){
				if(i & (1 << j)){
					v.first += p[j].first;
					v.second += p[j].second;
				}else{
					v.first -= p[j].first;
					v.second -= p[j].second;
				}
			}
			answer = min(answer, distance(v));
		}
		
		cout << answer << "\n";
	}
	
	return 0;
}