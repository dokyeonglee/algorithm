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
		cout << "A";
	}else if(n == 2 or arr[0] == arr[1]){
		
		bool possible = true;
		
		for(int i = 0; i < n and possible; i++){
			if(arr[0] != arr[i]){
				possible = false;
			}
		}
		
		if(possible){
			cout << arr[0];
		}else if(n == 2){
			cout << "A";
		}else{
			cout << "B";
		}
		
	}else{
		
		bool possible = true;
		
		if((arr[2] - arr[1]) % (arr[1] - arr[0]) != 0){
			possible = false;
		}
		
		int a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
		int b = arr[1] - a * arr[0];
		
		
		for(int i = 0; i < n - 1 and possible; i++){
			if(arr[i] * a + b != arr[i + 1]){
				possible = false;
			}
		}
		
		if(possible){
			cout << a * arr.back() + b;	
		}else{
			cout << "B";
		}
		
	}
	
	return 0;
}