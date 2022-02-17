#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	vector<long long> C(10005);
	C[1] = 1;
	C[0] = 1;
	
	int n, k;
	cin >> n >> k;
	
	for(int i = 2; i <= n + k - 1; i++){
		for(int j = i; j >= 1; j--){
			C[j] = (C[j - 1] + C[j]) % 1000000000;
		}
	}
	
	cout << C[n];
	
	return 0;
}