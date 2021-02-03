#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	for(int test_case = 1; test_case <= T; test_case++){
		int n;
		cin >> n;
		
		vector<int> candidate(n + 1);
		for(int i = 0; i < n; i++){
			int num;
			cin >> num;
			cin >> candidate[num];
		}
		
		int answer = 0;
		int temp = candidate[1];
		
		for(int i = 1; i <= n; i++){
			if(candidate[i] <= temp){
				answer++;
				temp = candidate[i];
			}
		}
		
		cout << answer << '\n';
	}
	
	return 0;
}