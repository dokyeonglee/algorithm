#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<char> s(n);
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	
	
	int left = 0;
	int right = n - 1;
	string answer = "";
	
	while(left <= right){
		if(s[left] < s[right]){
			answer += s[left++];
		}else if(s[left] > s[right]){
			answer += s[right--];
		}else{
			
			int temp_left = left + 1;
			int temp_right = right - 1;
			int temp_size = answer.size();
			
			while(temp_left <= temp_right){
				if(s[temp_left] < s[temp_right]){
					answer += s[left++];
					break;
				}else if(s[temp_left] > s[temp_right]){
					answer += s[right--];
					break;
				}else{
					temp_left++;
					temp_right--;
				}
			}
			if(temp_size == answer.size()){
				answer += s[left++];
			}
		}
		
	}
	
	for(int i = 0; i < answer.size(); i++){
		if(i != 0 and i % 80 == 0){
			cout << "\n";
		}
		cout << answer[i];	
	}
	
	return 0;
}