#include <iostream>
#include <vector>

using namespace std;

long long dfs(vector<int> arr, long long time, int c){
	
	long long sum = 0;
	for(int i = 0; i < arr.size(); i++){
		sum += time / arr[i];
	}
	
	if(c == 0){
		return sum;
	}
	
	long long result = 0;
	for(int i = 0; i < arr.size(); i++){
		if(arr[i] > 1){
			arr[i]--;
			result = max(result, dfs(arr, time, c - 1));
			arr[i]++;
		}
	}
	
	return max(result, sum);
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k, c;
	cin >> n >> k >> c;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	long long left = 1;
	long long right = k * 1000000ll;
	long long answer = -1;
	
	while(left <= right){
		long long mid = (left + right) / 2;
		if(k <= dfs(arr, mid, c)){
			answer = mid;
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
	
	cout << answer;
	
	return 0;
}