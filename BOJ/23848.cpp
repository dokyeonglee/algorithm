#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	long long n;
	cin >> n;
	
	for(long long i = 2; i <= 1000000; i++){
		long long temp = 1 + i + i * i;
		int cnt = 3;
		while(n % temp != 0 and temp < n){
			temp = temp * i + 1;
			cnt++;
		}
		if(n % temp == 0){
			cout << cnt << "\n";
			long long answer = n / temp;
			for(int j = 0; j < cnt; j++){
				cout << answer << " ";
				answer *= i;
			}
			return 0;
		}
	}
	
	cout << -1;
	
	return 0;
}