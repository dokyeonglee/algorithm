#include <iostream>
using namespace std;

int main() {
	
	int d, p, q;
	cin >> d >> p >> q;
	
	if(p < q){
		swap(p, q);
	}
	
	int _max = d + (p - d % p) % p;
	int t = min(_max / p, q);
	
	int answer = _max;
	for(int i = 0; i <= t and p * i <= d; i++){
		int result = p * i + (d - p * i) + (q - (d - p * i) % q) % q;
		if(abs(answer - d) > abs(result - d)){
			answer = result;
		}
	}
	
	cout << answer;
	
	return 0;
}