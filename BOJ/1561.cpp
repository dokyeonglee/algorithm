#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> rides(m);
	for(int i = 0; i < m; i++){
		cin >> rides[i];
	}
	
	long long lo = 0;
	long long hi = 2e9 * 30;
	long long time = 0;
	
	if(n <= m){
		cout << n;
		return 0;
	}
	
	while(lo <= hi){
		
		long long mid = (lo + hi) / 2;
		long long cnt = m;

		for(int i = 0; i < m; i++){
			cnt += mid / rides[i];
		}
		
		if(cnt < n){
			lo = mid + 1;
		}else{
			hi = mid - 1;
			time = mid;
		}
	}
	
	long long cnt = m;
	
	for(int i = 0; i < m; i++){
		cnt += (time - 1) / rides[i];
	}
	
	for(int i = 0; i < m; i++){
		if(time % rides[i] == 0){
			cnt++;
		}
		if(cnt == n){
			cout << i + 1;
			break;
		}
	}
	
	return 0;
}