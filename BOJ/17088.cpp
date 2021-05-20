#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	if(n == 1){
		cout << 0;
		return 0;
	}
	
	int answer = 987654321;
	
	for(int i = -1; i <= 1; i++){
		for(int j = -1; j <= 1; j++){
			
			int result = abs(i) + abs(j);
			
			int diff = (arr[1] + j) - (arr[0] + i);
			int next = arr[1] + j;
			bool possible = true;
			
			for(int k = 2; k < n; k++){
				
				next += diff;
				
				if(arr[k] == next){
					continue;
				}
				
				if(abs(arr[k] - next) == 1){
					result++;
					continue;
				}
				
				possible = false;
				break;
			}
			
			if(possible){
				answer = min(answer, result);
			}
			
		}
	}
	
	if(answer == 987654321){
		answer = -1;
	}
	
	cout << answer;
	
	return 0;
}