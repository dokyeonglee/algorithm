#include <iostream>
#include <tuple>

using namespace std;

long long gcd(long long a, long long b){
	return b ? gcd(b, a % b) : a;
}

tuple<long long, long long, long long> xgcd(long long a, long long b){
	if(b == 0){
		return make_tuple(1, 0, a);
	}
	long long x, y, d;
	tie(x, y, d) = xgcd(b, a % b);
	return make_tuple(y, x - a / b * y, d);
}

long long inverse(long long a, long long b){
	return (get<0>(xgcd(a, b)) + b) % b;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		long long K, C;
		cin >> K >> C;
		if(gcd(K, C) != 1){
			cout << "IMPOSSIBLE\n";
		}else{
			if(K == 1){
				if(C > 1){
					cout << "1\n";
				}else{
					cout << "2\n";
				}
			}else{
				long long X = C == 1 ? K + 1 : inverse(C, K);
				if(X > 1e9){
					cout << "IMPOSSIBLE\n";
				}else{
					cout << X << "\n";
				}
			}
		}
	}
	
	return 0;
}