#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;

void solve(int k){
	if(k == 1){
		return;
	}
	for(int i = k - 1; i >= 1; i--){
		if(k % i == 0){
			cnt++;
			solve(k - i);
			break;
		}
	}
}

int main() {
	
	int k;
	cin >> k;
	
	if(k == 1){
		cout << "Kali";
		return 0;
	}
	
	solve(k);	
	if(cnt % 2 == 0){
		cout << "Ringo";	
	}else{
		cout << "Kali";
	}
	
	return 0;
}