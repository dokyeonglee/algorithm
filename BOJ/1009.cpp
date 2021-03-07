#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long solve(int a, int b){
	
	if(b == 1){
		return a % 10;
	}
	
	long long temp = solve(a, b / 2);
	long long answer = temp * temp;
	
	if(b % 2 == 1){
		answer *= a;	
	}
	
	return answer % 10;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		
		int a, b;
		cin >> a >> b;
		
		long long answer = solve(a, b);
		
		if(answer == 0){
			answer = 10;
		}
		
		cout << answer << '\n';
		
	}
	
	return 0;
}