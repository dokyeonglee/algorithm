#include <iostream>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	int result = 0;
	int s = -1;
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if((x & k) == x){
			result |= x;
			if(s == -1){
				s = i + 1;
			}
			if(result == k){
				cout << s << " " << i + 1;
				return 0;
			}
		}else{
			result = 0;
			s = -1;
		}
	}
	
	cout << -1;
		
	return 0;
}