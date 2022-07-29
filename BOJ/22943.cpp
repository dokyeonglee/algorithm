#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool valid(int num, int k){
	vector<bool> visited(10, false);
	int cnt = 0;
	while(num > 0){
		if(visited[num % 10]) return false;
		visited[num % 10] = true;
		num /= 10;
		cnt++;
	}
	return cnt == k;
}

int main() {
	
	vector<bool> is_prime(1e5 + 1, true);
	is_prime[0] = is_prime[1] =false;
	
	for(int i = 2; i * i <= 1e5; i++){
		if(is_prime[i]){
			for(int j = i * i; j <= 1e5; j += i){
				is_prime[j] = false;
			}
		}
	}
	
	vector<bool> temp(1e5 + 1);
	for(long long i = 2; i <= 1e5; i++){
		if(is_prime[i]){
			for(long long j = i; j * i <= 1e5; j++){
				if(is_prime[j]){
					temp[i * j] = true;
				}
			}
		}
	}
	
	int k, m;
	cin >> k >> m;
	
	int answer = 0;
	for(int i = 1; i <= 98765; i++){
		int num = i;
		if(!valid(num, k)){
			continue;
		}
		if((num > 2 and num % 2 == 1 and is_prime[num - 2]) or (num > 6 and num % 2 == 0)){
			while(num % m == 0){
				num /= m;
			}
			if(temp[num]){
				answer++;
			}
		}
	}
	
	cout << answer;
	
	return 0;
}