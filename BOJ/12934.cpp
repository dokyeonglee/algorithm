#include <iostream>
#include <cmath>

using namespace std;

int main() {
	
	long long a, b;
	cin >> a >> b;
	
	long long d = sqrtl(1 + 8 * (a + b));
	
	if(d *d != 1 + 8 * (a + b)){
		cout << -1;
	}else{
		long long n = (d - 1) / 2;
        if(a == 0){
            cout << 0;
        }else if(n >= a){
			cout << 1;
		}else{
			long long answer = 0;
			for(long long i = n; i >= 1; i--){
				if(a >= i){
					a -=i;
					answer++;
				}
				if(a == 0){
					break;
				}
			}
			cout << answer;
		}
	}
	
	return 0;
}