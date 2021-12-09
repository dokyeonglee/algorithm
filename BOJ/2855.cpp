#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, s;
	cin >> n >> s;
	
	vector<int> arr(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	
	map<int, int> m;
	
	for(int i = 1; i <= n; i++){
		int left = 0;
		int right = min(i, n - i);
		int mid = (left + right) / 2;
		int result = 0;
		while(left <= right){
			mid = (left + right) / 2;
			int left_sum = arr[i] - arr[i - mid];
			int right_sum = arr[i + mid] - arr[i];
			if(left_sum <= s and right_sum <= s){
				result = max(result, mid);
				left = mid + 1;
			}else{
				right = mid - 1;
			}
		}
		
		m[i - result + 1] = max(m[i - result + 1], result);
	}
	
	int result = 0;
	
	for(int i = 1; i <= n; i++){
		result = max(result - 2, m[i] * 2);
		cout << result << "\n";
	}
	
	return 0;
}