#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	vector<bool> is_prime(1e7 + 1, true);
	is_prime[0] = is_prime[1] = false;
	
	for(int i = 2; i * i <= 1e7; i++){
		if(is_prime[i]){
			for(int j = i * i; j <= 1e7; j += i){
				is_prime[j] = false;
			}
		}
	}
	
	long long a, b;
	cin >> a >> b;
	
	long long answer = 0;
	
	for(long long i = 2; i <= 1e7; i++){
		if(is_prime[i]){
			for(__int128 j = i * i; j <= b; j *= i){
				if(j >= a){
					answer++;				
				}
			}
		}
	}
	
	cout << answer;
	
	return 0;
}