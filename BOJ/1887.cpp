#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T, n;
	cin >> T >> n;
	
	vector<int> hate(n);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		for(int j = 0; j < x; j++){
			int y;
			cin >> y;
			hate[i] |= (1 << (y - 1)) ;
		}
	}
	
	int answer = 0;
	for(int i = 0; i < (1 << T); i++){
		int cnt = 0;
		for(int j = 0; j < n; j++){
			if((i & hate[j]) != hate[j]){
				cnt++;
			}else{
				break;
			}
		}
		if(cnt == n){
			answer++;
		}
	}
	
	cout << answer;
	
	return 0;
}