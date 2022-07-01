#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	
	vector<bool> is_prime(5e5 + 1, true);
	is_prime[0] = is_prime[1] = false;
	
	for(int i = 2; i * i <= 5e5; i++){
		if(is_prime[i]){
			for(int j = i * i; j <= 5e5; j += i){
				is_prime[j] = false;
			}
		}
	}
	
	int n;
	cin >> n;
	
	vector<int> factor;
	set<int> s;
	for(int i = 1; i * i <= n; i++){
		if(n % i == 0){
			factor.push_back(i);
			s.insert(i);
			if(i * i != n){
				factor.push_back(n / i);
				s.insert(n / i);
			}
		}
	}

	long long k = n / 2;
	cout << k * (k - 1) + k * (n & 1) << "\n";
	
	int cnt = 0;
	for(int i = 0; i < factor.size(); i++){
		for(int j = i; j < factor.size(); j++){
			if(s.count(factor[i] + factor[j])){
				cnt++;
			}
		}
	}
	
	cout << cnt << "\n";
	
	cnt = 0;
	for(int i = 3; i <= n - 2; i += 2){
		if(is_prime[i] and is_prime[i + 2]){
			cnt++;
		}	
	}
	
	cout << cnt;
	
	
	return 0;
}