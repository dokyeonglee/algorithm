#include <iostream>
#include <vector>

using namespace std;

vector<int> sieve(int num){
	
	vector<int> is_prime(num + 1, true);
	is_prime[0] = is_prime[1] = false;
	
	for(int i = 2; i * i <= num; i++){
		if(is_prime[i]){
			for(int j = i * i; j <= num; j += i){
				is_prime[j] = false;
			}
		}
	}
	
	vector<int> prime;
	for(int i = 2; i <= num; i++){
		if(is_prime[i]){
			prime.push_back(i);
		}
	}
	
	return prime;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> prime = sieve(n);
	
	int left = 0;
	int right = 0;
	int answer = 0;
	int sum = 0;
	
	
	while(1){
		
		if(sum >= n){
			sum -= prime[left++];		
		}else if(right >= prime.size()){
			break;
		}else{
			sum += prime[right++];
		}
		
		if(sum == n){
			answer++;
		}
		
	}
	
	cout << answer;
	
	return 0;
}