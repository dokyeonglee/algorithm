#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double dist(long long x1, long long y1, long long x2, long long y2){
	return (1 + (y1 < y2) + (y1 <= y2)) * sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	vector<long long> x(n + 1);
	vector<long long> y(n + 1);
	
	for(int i = 1; i <= n; i++){
		cin >> x[i];
	}
	
	for(int i = 1; i <= n; i++){
		cin >> y[i];
	}
	
	vector<double> psum(n + 1);
	for(int i = 2; i <= n; i++){
		psum[i] = psum[i - 1] + dist(x[i - 1], y[i - 1], x[i], y[i]);
	}
	
	vector<double> psum2(n + 1);
	for(int i = n - 1; i >= 1; i--){
		psum2[i] = psum2[i + 1] + dist(x[i + 1], y[i + 1], x[i], y[i]);
	}
    
	cout.fixed;
	cout.precision(15);
	
	for(int i = 0; i < q; i++){
		int a, b;
		cin >> a >> b;
		if(a < b){
			cout << psum[b] - psum[a] << "\n";
		}else{
			cout << psum2[b] - psum2[a] << "\n";
		}
	}
	
	return 0;
}