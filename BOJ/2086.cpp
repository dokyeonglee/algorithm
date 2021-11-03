#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> pow(vector<vector<long long>> a, long long n){
	
	if(n == 0){
		return {{1, 0}, {0, 1}};
	}
	
	vector<vector<long long>> result = pow(a, n / 2);
	vector<vector<long long>> temp(result);
	
	result[0][0] = (temp[0][0] * temp[0][0] + temp[0][1] * temp[1][0]) % 1000000000;
	result[0][1] = (temp[0][0] * temp[0][1] + temp[0][1] * temp[1][1]) % 1000000000;
	result[1][0] = (temp[1][0] * temp[0][0] + temp[1][1] * temp[1][0]) % 1000000000;
	result[1][1] = (temp[1][0] * temp[0][1] + temp[1][1] * temp[1][1]) % 1000000000;
	
	if(n % 2 == 1){
		temp = result;
		result[0][0] = (temp[0][0] * a[0][0] + temp[0][1] * a[1][0]) % 1000000000;
		result[0][1] = (temp[0][0] * a[0][1] + temp[0][1] * a[1][1]) % 1000000000;
		result[1][0] = (temp[1][0] * a[0][0] + temp[1][1] * a[1][0]) % 1000000000;
		result[1][1] = (temp[1][0] * a[0][1] + temp[1][1] * a[1][1]) % 1000000000;
	}
	
	return result;
}

int main() {
	
	long long a, b;
	cin >> a >> b;
	cout << (pow({{1, 1}, {1, 0}}, b + 2)[0][1] - pow({{1, 1}, {1, 0}}, a + 1)[0][1] + 1000000000) % 1000000000;
		
	return 0;
}