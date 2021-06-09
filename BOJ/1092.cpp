#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> capability(n);
	for(int i = 0; i < n; i++){
		cin >> capability[i];
	}
	
	int m;
	cin >> m;
	
	vector<int> box(m);
	for(int i = 0; i < m; i++){
		cin>> box[i];
	}
	
	sort(capability.begin(), capability.end());
	sort(box.begin(), box.end());
	
	if(box.back() > capability.back()){
		cout << -1;
	}else{
		
		int answer = 0;
		int idx = n - 1;
		int cnt = 0;
		
		while(cnt < m){
			
			answer++;
			
			for(int i = m - 1; i >= 0 and idx >= 0; i--){
				
				if(box[i] > 0 and capability[idx] >= box[i]){
					box[i] = -1;
					cnt++;
					idx--;
				}
				
			}
			
			idx = n - 1;
			
		}
		
		cout << answer;
	}
	
	return 0;
}