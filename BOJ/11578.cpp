#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> arr(m);
	for(int i = 0; i < m; i++){
		int o;
		cin >> o;
		for(int j = 0; j < o; j++){
			int p;
			cin >> p;
			p--;
			arr[i] |= (1 << p);
		}
	}
	
	int answer = 987654321;
	for(int i = 0; i < (1 << m); i++){
		int solve = 0;
		for(int j = 0; j < m; j++){
			if(i & (1 << j)){
				solve |= arr[j];
			}
		}
		if(solve == (1 << n) - 1){
			answer = min(answer, __builtin_popcount(i));
		}
	}
	
	if(answer == 987654321){
		answer = -1;
	}
	
	cout << answer;
	
	return 0;
}