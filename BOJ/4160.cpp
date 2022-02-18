#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while(1){
		
		int n;
		cin >> n;
		
		if(n == 0){
			break;
		}
		
		vector<long long> value(n);
		for(int i = 0; i < n; i++){
			cin >> value[i];
		}
		
		map<long long, long long> m;
		
		int x = pow(3, n / 2);
		
		for(int i = 0; i < x; i++){
			
			long long jack = 0; 
			long long jill = 0;
			long long sell = 0;
			int temp = i;
			int idx = 0;
			
			while(idx < n / 2){
				if(temp % 3 == 0){
					jack += value[idx];
				}else if(temp % 3 == 1){
					jill += value[idx];
				}else{
					sell += value[idx];
				}
				idx++;
				temp /= 3;
			}
			
			if(m.count(jack - jill)){
				m[jack - jill] = min(m[jack - jill], sell);
			}else{
				m[jack - jill] = sell;
			}
			
		}
		
		x = pow(3, n - n / 2);
		
		long long answer = 1e18;
		
		for(int i = 0; i < x; i++){
			long long jack = 0; 
			long long jill = 0;
			long long sell = 0;
			int temp = i;
			int idx = n / 2;
			while(idx < n){
				if(temp % 3 == 0){
					jack += value[idx];
				}else if(temp % 3 == 1){
					jill += value[idx];
				}else{
					sell += value[idx];
				}
				idx++;
				temp /= 3;
			}
			
			if(m.count(jill - jack)){
				answer = min(answer, m[jill - jack] + sell);
			}
			
		}
		
		cout << answer << "\n";
		
	}
	
	return 0;
}