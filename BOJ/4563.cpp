#include <iostream>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while(1){
		long long a;
		cin >> a;
		if(a == 0){
			break;
		}
		long long answer = 0;
		long long aa = a * a;
		for(int i = 1; i <= a; i++){
			if(aa % i == 0){
				if((aa / i + i) % 2 == 0 and (aa / i - i) % 2 == 0 
				and (aa / i - i) / 2 > a){
					answer++;
				}
			}
		}
		cout << answer << "\n";
	}
	
	return 0;
}