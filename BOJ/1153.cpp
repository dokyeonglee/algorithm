#include <iostream>
#include <vector>

using namespace std;

vector<int> sieve(int n){
	
	vector<bool> is_prime(n + 1, true);
	
	is_prime[0] = is_prime[1] = false;
	
	for(int i = 2; i * i <= n; i++){
		if(is_prime[i]){
			for(int j = i * i; j <= n; j += i){
				is_prime[j] = false;
			}	
		}
	}
	
	vector<int> prime;
	
	for(int i = 2; i <= n; i++){
		if(is_prime[i]){
			prime.push_back(i);
		}
	}
	
	return prime;
}

pair<int, int> goldbach(vector<int>& prime, int n){
	for(int i = 0; i < prime.size(); i++){
		for(int j = 0; j < prime.size(); j++){
			if(prime[i] + prime[j] == n){
				return make_pair(prime[i], prime[j]);
			}else if(prime[i] + prime[j] >= n){
				break;
			}
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> prime = sieve(n);

	if(n < 8){
		cout << -1;
	}else{
		if(n % 2 == 0){
			pair<int, int> answer = goldbach(prime, n - 4); 
			cout << "2 2 " << answer.first << " " << answer.second;
		}else{
			pair<int, int> answer = goldbach(prime, n - 5); 
			cout << "2 3 " << answer.first << " " << answer.second;
		}
	}
	
	return 0;
}