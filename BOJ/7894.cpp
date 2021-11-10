#include <iostream>
#include <cmath>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		int m;
		cin >> m;
		double answer = 0;
		for(int i = m; i > 0; i--){
			answer += log10(i);
		}
		cout << (int)(answer + 1) << "\n";
	}
	
	return 0;
}