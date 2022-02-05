#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
		int n;
		cin >> n;
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		int answer = 0;
		for(int i = 0; i < n - 1; i++){
			answer = gcd(answer, abs(arr[i] - arr[i + 1]));
		}
		
		if(answer == 0){
			cout << "INFINITY\n";
		}else{
			cout << answer << "\n";
		}
		
	}
	return 0;
}