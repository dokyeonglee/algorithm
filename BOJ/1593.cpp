#include <iostream>
#include <map>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	string str1, str2;
	cin >> str1 >> str2;
	
	map<char, int> str1_cnt;
	map<char, int> str2_cnt;
	
	for(int i = 0; i < n; i++){
		str1_cnt[str1[i]]++;
	}
	
	for(int i = 0; i < n; i++){
		str2_cnt[str2[i]]++;
	}
	
	int left = 0;
	int right = n - 1;
	
	int N = str1_cnt.size();
	int answer = 0;
	
	while(1){
			
		if(str2_cnt.size() == N){
			
			bool possible = true;

			for(int i = left; i <= right; i++){
				if(str1_cnt[str2[i]] != str2_cnt[str2[i]]){
					possible = false;
					break;
				}
			}
			
			if(possible){
				answer++;
			}
			
		}
		
		if(--str2_cnt[str2[left]] == 0){
			str2_cnt.erase(str2[left]);
		}
		
		left++;
		right++;
		
		if(right >= m){
			break;
		}
		
		str2_cnt[str2[right]]++;
		
	}
	
	cout << answer;
	
	return 0;
}