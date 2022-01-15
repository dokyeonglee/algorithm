#include <iostream>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int x = 0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(a % 2 == 1){
			x ^= (a + 1) / 2;
		}else{
			x ^= (a - 2) / 2;
		}
	}
	
	if(x == 0){
		cout << "cubelover";
	}else{
		cout << "koosaga";
	}
		
	return 0;
}