#include <iostream>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while(1){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		
		int answer = 0;
		for(int i = 1; i * (i + 1) / 2 <= n - i; i++){
			if((n - i - i * (i + 1) / 2) % i == 0){
				answer++;
			}
		}
		cout << answer << "\n";
	}
	
	return 0;
}