#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	long long x, k;
	cin >> x >> k;
	
	vector<bool> check(65);
	
	int idx = 0;
	
	while(x > 0){
		check[idx++] = x % 2;
		x /= 2;
	}
	
	idx = 0;
	
	long long answer = 0;
	long long p = 1;
	
	while(k > 0){
		if(!check[idx++]){
			if(k % 2){
				answer += p;
			}
			k /= 2;
		}
		p *= 2;
	}
	
	cout << answer;
	
	return 0;
}