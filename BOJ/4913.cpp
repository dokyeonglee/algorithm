#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<bool> is_prime(1000001, true);
	is_prime[0] = is_prime[1] = false;
	
	vector<int> prime(1000001);
	vector<int> euler(1000001);
	
	euler[2] = 1;	

	for(int i = 2; i * i <= 1000000; i++){
		if(is_prime[i]){
			for(int j = i * i; j <= 1000000; j += i){
				is_prime[j] = false;
			}
		}
	}
	
	for(int i = 1; i <= 1000000; i++){
		if(is_prime[i]){
			prime[i] = 1;
			if(i % 4 == 1){
				euler[i] = 1;
			}
		}
		prime[i] += prime[i - 1];
		euler[i] += euler[i - 1];
	}
	
	while(1){
		int l, u;
		cin >> l >> u;
		if(l == -1 and u == -1){
			break;
		}
		cout << l << " " << u << " ";
		l = max(l, 1);
		u = max(u, 1);
		cout << prime[u] - prime[l - 1] << " " << euler[u] - euler[l - 1] << "\n";
	}
	
	return 0;
}