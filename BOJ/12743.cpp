#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double get_b_amount(vector<int>& ga, vector<int>& gb, vector<int>& w, double a_amount){
	double b_amount = 1e9;
	for(int i = 0; i < gb.size(); i++){
		b_amount = min(b_amount, (w[i] - ga[i] * a_amount) / gb[i]);
	}
	return b_amount;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, x, y;
	cin >> n >> x >> y;
	
	vector<int> ga(n);
	vector<int> gb(n);
	
	for(int i = 0; i < n; i++){
		cin >> ga[i];
	}
	
	for(int i = 0; i < n; i++){
		cin >> gb[i];
	}
	
	vector<int> w(n);
	for(int i = 0; i < n; i++){
		cin >> w[i];
	}
	
	double left = 0;
	double right = 1e9;
	
	for(int i = 0; i < n; i++){
		right = min(right, (double)w[i] / ga[i]);
	}
	
	for(int i = 0; i < 100; i++){
		double p1 = (left * 2 + right) / 3;
		double p2 = (left + 2 * right) / 3;
		if(p1 * x + get_b_amount(ga, gb, w, p1) * y < p2 * x + get_b_amount(ga, gb, w, p2) * y){
			left = p1;
		}else{
			right = p2;
		}
		
	}
	
	cout << fixed;
	cout.precision(10);
	
	double a_amount = (left + right) / 2;
	double b_amount = get_b_amount(ga, gb, w, (left + right) / 2);
	
	cout << a_amount * x + get_b_amount(ga, gb, w, a_amount) * y << "\n";
	cout << a_amount << " " << b_amount;
	
	return 0;
}