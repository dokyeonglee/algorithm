#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b){
	return b ? gcd(b, a % b) : a;
}

int main() {
	
	long long a, b, lcm;
	cin >> a >> b >> lcm;
	
	vector<long long> d;
	for(long long i = 1; i * i <= lcm; i++){
		if(lcm % i == 0){
			d.push_back(i);
			if(i * i != lcm){
				d.push_back(lcm / i);
			}
		}
	}
	
	long long l = a * b / gcd(a, b);
	long long answer = 1e18;
	for(int i = 0; i < d.size(); i++){
		if(l * d[i] / gcd(l, d[i]) == lcm){
			answer = min(answer, d[i]);
		}
	}
	
	if(answer == 1e18){
		answer = -1;
	}
	
	cout << answer;
	
	return 0;
}