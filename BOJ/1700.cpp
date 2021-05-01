#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	
	vector<int> arr(k + 1);
	vector<queue<int>> q(k + 1);
	
	for(int i = 1; i <= k; i++){
		cin >> arr[i];
		q[arr[i]].push(i);
	}
	
	int answer = 0;
	int plugged_cnt = 0;
	vector<bool> plugged(k + 1, false);
	
	for(int i = 1; i <= k; i++){
		
		q[arr[i]].pop();
		
		if(!plugged[arr[i]]){
			
			if(plugged_cnt == n){

				int idx = 0;
				int last = 0;
				
				for(int j = 1; j <= k; j++){
					if(plugged[j]){
						if(q[j].empty()){
							idx = j;
							break;
						}
						if(last < q[j].front()){
							last = q[j].front();
							idx = j;
						}
					}
				}
				
				plugged[idx] = false;
				plugged_cnt--;
				answer++;
			}
			
			plugged_cnt++;
			plugged[arr[i]] = true;
			
		}
		
	}
	
	cout << answer << "\n";
	
	return 0;
}