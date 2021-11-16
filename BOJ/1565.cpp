#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b){
	return b ? gcd(b, a % b) : a;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int d, m;
	cin >> d >> m;
	
	long long l = 1;
	for(int i = 0; i < d; i++){
		long long x;
		cin >> x;
		l = l * x / gcd(l, x);
	}
	
	long long g = 0;
	for(int i = 0; i < m; i++){
		long long x;
		cin >> x;
		g = gcd(x, g);
	}
	
	long long answer = 0;
	for(long long i = 1; i * i <= g; i++){
		if(g % i == 0){
			if(i % l == 0){
				answer++;
			}
		}
		if(i * i != g){
			if(g % (g / i) == 0){
				if(g / i % l == 0){
					answer++;
				}
			}
		}
	}
	
	cout << answer;
	
	return 0;
}