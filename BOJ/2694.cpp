#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		
		int n;
		cin >> n;
		
		vector<int> psum(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> psum[i];
			psum[i] += psum[i - 1];
		}
		
		int answer = psum[n];
		for(int i = 1; i <= n; i++){
			if(psum[n] % psum[i] == 0){
				int cnt = psum[n] / psum[i];
				bool check = true;
				for(int j = 1; j <= cnt; j++){
					if(*lower_bound(psum.begin() + 1, psum.end(), psum[i] * j) != psum[i] * j){
						check = false;
						break;
					}
				}
				if(check){
					answer = psum[i];
					break;
				}
			}
		}
		
		
		cout << answer << "\n";
		
	}
	
	return 0;
}