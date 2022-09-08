	#include <iostream>
	#include <vector>
	
	using namespace std;
	
	int main() {
		
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		
		int n, l, c;
		cin >> n >> l >> c;
	
		int answer;
		int cnt = (c + 1) / (l + 1);
		if(cnt % 13 == 0){
			cnt--;
		}
		
		int r = n % cnt;		
		if(r){
			if(r % 13 == 0){
				answer = n / cnt + 2 - (n / cnt >= 1 and cnt != r + 1);
			}else{
				answer = n / cnt + 1;
			}
		}else{
			answer = n / cnt;
		}
		
		
		cout << answer;
		
		return 0;
	}