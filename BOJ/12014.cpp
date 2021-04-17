#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	for(int test_case = 1; test_case <= T; test_case++){
		
		int n, k;
		cin >> n >> k;
		
		vector<int> vt(1, -1);
		for(int i = 0; i < n; i++){
			
			int x;
			cin >> x;
			
			if(vt.back() < x){
				vt.push_back(x);
			}else{
				auto it = lower_bound(vt.begin(), vt.end(), x);
				*it = x;
			}
			
		}
		
		int answer = vt.size() - 1 >= k ? 1 : 0;
		cout << "Case #" << test_case << '\n';
		cout << answer << '\n';
		
	}
	
	return 0;
}