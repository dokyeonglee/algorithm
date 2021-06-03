#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		
		int n;
		cin >> n;
		
		vector<string> arr(n);
		
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		
		sort(arr.begin(), arr.end());
		
		bool result = true;
		
		for(int i = 0; i < n - 1; i++){
			if(arr[i].size() < arr[i + 1].size() and arr[i + 1].find(arr[i]) == 0){
				result = false;
				break;
			}
		}
		
		if(result){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
		
	}
	
	return 0;
}