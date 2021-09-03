#include <iostream>
#include <vector>

using namespace std;

vector<long long> bit(63);

long long solve(long long a){
	long long result = 0;
	for(int i = 62; i >= 0; i--){
		if(a & (1ll << i)){
			a -= 1ll << i;
			result += bit[i] + (a + 1);
		}
	}
	return result;
}

int main() {
	
	long long a, b;
	cin >> a >> b;
	
	bit[1] = 1;
	for(int i = 2; i < 63; i++){
		bit[i] = bit[i - 1] * 2 + (1ll << (i - 1));
	}
	
	cout << solve(b) - solve(a - 1);
	
	return 0;
}