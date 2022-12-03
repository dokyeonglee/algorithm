#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		
		int n;
		cin >> n;
		
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		
		int curr = n;
		vector<int> answer;
		
		while(curr > 1){
			for(int i = 0; i < curr; i++){
				if(arr[i] == curr){
					if(i + 1 == curr){
						curr--;
						break;
					}
					if(i != 0){
						answer.push_back(i + 1);
						reverse(arr.begin(), arr.begin() + i + 1);
					}
					answer.push_back(curr);
					reverse(arr.begin(), arr.begin() + curr);
					break;
				}
			}
		}
		
		cout << answer.size() << " ";
		for(int i = 0; i < answer.size(); i++){
			cout << answer[i] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}