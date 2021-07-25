#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	string str;
	cin >> str;
	
	if(str.size() <= n){
		cout << str.size();
	}else{
		
		int lo = 0;
		int hi = 0;
		int c = 0;
		
		vector<int> cnt(26);
		
		int answer = 0;
		
		while(1){
			
			while(c <= n and hi < str.size()){
				if(++cnt[str[hi++] - 'a'] == 1){
					c++;	
				}
				if(c > n){
					break;
				}
				answer = max(answer, hi - lo);
			}
			
			if(hi == str.size()){
				break;
			}
			
			while(c > n){
				if(--cnt[str[lo] - 'a'] == 0){
					c--;
				}
				lo++;
			}
		}
		
		cout << answer;	
		
	}
	
	return 0;
}