#include <iostream>
using namespace std;

int solve(string& str, int left, int right, int cnt){
	while(left < right){
		if(str[left] != str[right]){
			if(cnt == 0){
				if(solve(str, left + 1, right, 1) == 0 or solve(str, left, right - 1, 1) == 0){
					return 1;
				}else{
					return 2;
				}
			}else{
				return 2;
			}
		}else{
			left++;
			right--;
		}
	}
	return 0;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		string str;
		cin >> str;
		cout << solve(str, 0, str.size() - 1, 0) << "\n";
	}
	
	return 0;
}