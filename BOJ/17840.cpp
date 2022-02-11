#include <iostream>
#include <vector>

using namespace std;

long long pisano(long long m){
	
	long long prev = 0;
	long long now = 1;
	long long result = 0;
	
	for(long long i = 0; i < m * m; i++){
		long long temp = now;
		now = (now + prev) % m;
		prev = temp;
		if(prev == 0 and now == 1){
			result = i + 1;
		}
	}
	
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int q, m;
	cin >> q >> m;
	
	int p = pisano(m);
	vector<long long> dp;
	
	dp.reserve(3 * p);
	dp.push_back(0);
	dp.push_back(1);
	
	long long f0 = 0;
	long long f1 = 1;
	long long f2 = 1;
	
	for(int i = 2; i < p; i++){
		vector<int> result;
		long long temp = f2;
		if(temp == 0){
			result.push_back(0);
		}else{
			while(temp > 0){
				result.push_back(temp % 10);
				temp /= 10;
			}
		}
		for(int j = result.size() - 1; j >= 0; j--){
			dp.push_back(result[j]);
		}
		f0 = f1;
		f1 = f2;
		f2 = (f0 + f1) % m;
	}
	
	while(q--){
		long long n;
		cin >> n;
		cout << dp[n % dp.size()] << "\n";
	}
	
	return 0;
}s