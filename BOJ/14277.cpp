#include <iostream>
using namespace std;

int main() {
	
	long long a, b, c, d, u;
	cin >> a >> b >> c >> d >> u;
	
	long long answer = 0;
	
	if(u >= a){
		answer += (u - a) / b + 1;
	}
	
	if(d == 1){
		if(u >= c and (c < a or (c - a) % b != 0)){
			answer++;
		}
	}else{
		while(u >= c){
			if((c < a or (c - a) % b != 0)){
				answer++;
			}
			c *= d;
		}
	}
	
	cout << answer;
	
	return 0;
}