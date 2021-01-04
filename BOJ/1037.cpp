#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> factor(n);
	for(int i = 0; i < n; i++){
		cin >> factor[i];
	}
	
	sort(factor.begin(), factor.end());
	cout << factor.front() * factor.back() << endl;
	
	return 0;
}