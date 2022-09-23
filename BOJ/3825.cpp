#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<bool> check(20001);
	for(int i = 0; i * i < 20000; i++){
		for(int j = i; i * i + j * j < 20000; j++){
			if(i * i + j * j > 1){
				check[i * i + j * j] = true;
			}
		}
	}
	
	int t;
	cin >> t;
	
	while(t--){
		int m, n;
		cin >> m >> n;
		int x = m * m + n * n;
		bool prime = true;
		for(int i = 2; i * i <= x; i++){
			if(x % i == 0){
				if(check[i] and check[x / i]){
					prime = false;
					break;
				}
			}
		}
		
		if(prime){
			cout << "P\n";
		}else{
			cout << "C\n";
		}
	}
	
	return 0;
}