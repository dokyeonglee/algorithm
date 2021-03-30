#include <iostream>
using namespace std;

int main() {
	
	int n, k, m;
	cin >> n >> k >> m;
	
	int answer;
	for(answer = 1; answer <= n; answer++){
		
		int target = k % (n - answer + 1);
		if(target == 0){
			target = n - answer + 1;	
		}
		
		if(m == target or answer == n){
			break;
		}else{
			if(target < m){
				m -= target;
			}else{
				m -= target;
				m += n - answer + 1;
			}
		}
	}
	
	cout << answer;
	
	return 0;
}