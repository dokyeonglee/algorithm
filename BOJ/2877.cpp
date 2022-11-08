#include <iostream>
using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	int temp = 1;
	int cnt = 1;
	while(((temp << 1) | 1) <= n){
		temp = (temp << 1) | 1;
		cnt++;
	}
	
	n -= (1 << cnt) - 1;
	
	while(cnt > 0){
		if(n & (1 << (cnt - 1))){
			cout << 7;
		}else{
			cout << 4;
		}
		cnt--;
	}
	
	return 0;
}