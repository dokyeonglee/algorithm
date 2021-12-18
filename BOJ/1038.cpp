#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<long long> decrease;
	for(int i = 0; i < (1 << 10); i++){
		vector<int> v;
		for(int j = 0; j < 10; j++){
			if(i & (1 << j)){
				v.push_back(-j);
			}
		}
		sort(v.begin(), v.end());
		long long num = 0;
		for(int j = 0; j < v.size(); j++){
			num = num * 10 + -v[j];
		}
		decrease.push_back(num);
	}
	
	sort(decrease.begin(), decrease.end());
	decrease.erase(unique(decrease.begin(), decrease.end()), decrease.end());
	
	if(n < decrease.size()){
		cout << decrease[n];
	}else{
		cout << -1;
	}
	
	return 0;
}