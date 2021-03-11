#include <iostream>
#include <vector>

using namespace std;

long long solve(vector<long long>& heights, int left, int right){
	
	if(left == right){
		return heights[left];
	}
	
	int mid = (left + right) / 2;
	
	long long result = max(solve(heights, left, mid), solve(heights, mid + 1, right));
	
	int lo = mid;
	int hi = mid + 1;
	
	long long height = min(heights[lo], heights[hi]);
	
	result = max(result, height * 2);
	
	while(left < lo or hi < right){
		
		if(hi < right and (lo == left or heights[lo - 1] < heights[hi + 1])){
			hi++;
			height = min(height, heights[hi]);
		}else{
			lo--;
			height = min(height, heights[lo]);
		}
		
		result 	= max(result, height * (hi - lo + 1));
	}
	
	return result;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while(1){
		
		int n;
		cin >> n;
		
		if(n == 0){
			break;
		}
		
		vector<long long> heights(n);
		for(int i = 0; i < n; i++){
			cin >> heights[i];
		}
		
		cout << solve(heights, 0, n - 1) << '\n';
	}
	
	
	return 0;
}