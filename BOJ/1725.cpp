#include <iostream>
#include <vector>

using namespace std;

long long solve(vector<long long>& height, int left, int right){
	
	if(left == right){
		return height[left];
	}
	
	int mid = (left + right) / 2;
	long long result = max(solve(height, left, mid), solve(height, mid + 1, right));
	int lo = mid;
	int hi = mid + 1;
	long long h = min(height[lo], height[hi]);
	
	result = max(result, 2ll * h);
	
	while(lo < left or hi < right){
		if(hi < right and (lo == left or height[lo - 1] < height[hi + 1])){
			h = min(h, height[++hi]);
		}else{
			h = min(h, height[--lo]);
		}
		result = max(result, h * (hi - lo + 1));
	}
	
	return result;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<long long> height(n);
	for(int i = 0; i < n; i++){
		cin >> height[i];
	}
	
	cout << solve(height, 0, n - 1);
	
	return 0;
}