#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	long long _p1, _p2, _p3, x;
	cin >> _p1 >> _p2 >> _p3 >> x;
	
	long long limit = 1e18;
	
	vector<long long> v;
	
	__int128 p1 = 1;
	__int128 p2 = 1;
	__int128 p3 = _p3;
	
	while(p1 < limit){
		p2 = 1;
		while(p1 * p2 < limit){
			p3 = 1;
			while(p1 * p2 * p3 < limit){
				v.push_back(p1 * p2 * p3);
				p3 *= _p3;
			}
			p2 *= _p2;
		}
		p1 *= _p1;
	}
	
	sort(v.begin(), v.end());

	cout << v[x];
	
	return 0;
}