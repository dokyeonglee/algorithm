#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> a(n);
	vector<int> b(n);
	
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		a[i] = x + y;
		b[i] = x - y;
	}
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	cout << max(a.back() - a.front(), b.back() - b.front());
	
	return 0;
}