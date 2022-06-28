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
	
	int answer = 0;
	bool check = false;
	bool check2 = false;
	
	while(!check){
		
		check = true;
		check2 = false;
		
		for(int i = 0; i < n; i++){
			if(arr[i]){
				check = false;
			}
			if(arr[i] % 2 == 1){
				arr[i]--;
				answer++;
				check2 = true;
			}
		}
		if(!check and !check2){
			answer++;
			for(int i = 0; i < n; i++){
				arr[i] /= 2;
			}
		}
	}
	
	cout << answer;
	
	return 0;
}