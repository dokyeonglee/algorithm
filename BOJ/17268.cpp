#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	vector<long long> catalan(n / 2 + 1);
	catalan[0] = 1;
	catalan[1] = 1;
	
	for(int i = 1; i < n / 2; i++){
		for(int j = 0; j <= i; j++){
			catalan[i + 1] = (catalan[i + 1] + catalan[i - j] * catalan[j]) % 987654321;
		}
	}
	
	cout << catalan[n / 2];
	
	return 0;
}