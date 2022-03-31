#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	vector<bool> is_prime(1000001, true);
	for(int i = 2; i * i <= 1000000; i++){
		if(is_prime[i]){
			for(int j = i * i; j <= 1000000; j += i){
				is_prime[j] = false;
			}
		}
	}
	
	int n;
	cin >> n;
	
	long long answer = 1;
	long long i = 2;
	
	while(i <= n){
		if(is_prime[i]){
			long long temp = i;
			while(temp * i <= n){
				temp *= i;
			}
			answer *= temp;
			answer %= 987654321;
		}
		i++;
	}
	
	cout << answer;
	
	return 0;
}