#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	vector<int> prime;
	for(int i = 2; i <= n; i++){
		bool is_prime = true;
		for(int j = 2; j * j <= i; j++){
			if(i % j == 0){
				is_prime = false;
				break;
			}
		}
		if(is_prime){
			prime.push_back(i);
		}
	}
	
	int left = 0;
	int right = prime.size() - 1;
	int answer = 0;
	
	while(left <= right){
		while(prime[left] * prime[right] <= n){
			left++;
			prime[right] *= prime[left];
		}
		right--;
		answer++;
	}
	
	cout << answer;
	
	return 0;
}