`#include <iostream>
#include <vector>

using namespace std;

long long get_cnt(vector<long long>& y, vector<long long>& d, long long mid){
	long long cnt = 0;
	for(int i = 0; i < y.size(); i++){
		cnt += abs(y[i] - (mid + abs((int)y.size() / 2 - i)));
		cnt += abs(d[i] - (mid + abs((int)y.size() / 2 - i)));
	}
	return cnt;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<long long> y(n);
	vector<long long> d(n);
	
	for(int i = 0; i < n; i++){
		cin >> y[i];
	}
	
	for(int i = 0; i < n; i++){
		cin >> d[i];
	}
	
	long long left = 0;
	long long right = 1e12 + 1;
	
	for(int i = 0; i < 100; i++){
		long long p1 = (2 * left + right) / 3;
		long long p2 = (left + 2 * right) / 3;
		if(get_cnt(y, d, p1) > get_cnt(y, d, p2)){
			left = p1;
		}else{
			right = p2;
		}
	}
	
	cout << get_cnt(y, d, (left + right) / 2);
	
	return 0;
}