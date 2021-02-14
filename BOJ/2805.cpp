#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int lo = 0;
	int hi = -1;
	
	vector<int> height(n);
	for(int i = 0; i < n; i++){
		cin >> height[i];
		hi = max(hi, height[i]);
	}
	
	int answer = 0;
	
	while(lo <= hi){
		
		int mid = (lo + hi) / 2;
		long long sum = 0;
		
		for(int i = 0; i < n; i++){
			if(mid < height[i]){
				sum += height[i] - mid;
			}
		}
		
		if(sum >= m){
			answer = max(answer, mid);
			lo = mid + 1;
		}else{
			hi = mid - 1;	
		}
	}
	
	cout << answer;
	
	return 0;
}