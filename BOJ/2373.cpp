#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	vector<long long> fib(40);
	fib[0] = fib[1] = 1;
	
	for(int i = 2; i < fib.size(); i++){
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	
	int n;
	cin >> n;
	
	auto it = lower_bound(fib.begin(), fib.end(), n) - fib.begin();
	
	int answer = -1;
	
	if(fib[it] != n){
		while(it-- > 0){
			if(n >= fib[it]){
				n -= fib[it];
				answer = fib[it];
			}
		}	
	}
	
	cout << answer;
	
	return 0;
}