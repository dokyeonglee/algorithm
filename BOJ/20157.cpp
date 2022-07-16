#include <iostream>
#include <map>

using namespace std;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	map<pair<int, int>, int> cnt;
	
	int n;
	cin >> n;
	
	int answer = 0;
	for(int i = 0; i < n; i++){
		int x, y, g;
		cin >> x >> y;
		g = abs(gcd(x, y));
		answer = max(answer, ++cnt[make_pair(x / g, y / g)]);
	}
	
	cout << answer;
	
	return 0;
}