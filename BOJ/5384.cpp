#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		int n, d;
		cin >> n >> d;
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		int answer = 987654321;
		for(int i = 0; i < (1 << d); i++){
			vector<int> temp(arr);
			int result = __builtin_popcount(i);
			for(int j = 0; j < d; j++){
				if(i & (1 << j)){
					for(int k = j - d; k <= j + d; k++){
						if(k >= 0 and k < n){
							temp[k] ^= 1;
						}
					}
				}
			}
			for(int j = d; j < n; j++){
				if(temp[j - d]){
					result++;
					for(int k = j - d; k <= j + d; k++){
						if(k >= 0 and k < n){
							temp[k] ^= 1;
						}
					}
				}
			}
			
			bool check = true;
			for(int j = 0; j < n; j++){
				if(temp[j]){
					check = false;
					break;
				}
			}
			
			if(check){
				answer = min(answer, result);
			}
			
		}
		
		if(answer == 987654321){
			cout << "impossible\n";
		}else{
			cout << answer << "\n";
		}
	}
		
	return 0;
}