#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> psum(vector<int>& arr){
	
	int n = arr.size();
	
	vector<int> result;
	
	for(int i = 0; i < n; i++){
		int sum = arr[i];
		result.push_back(sum);
		for(int j = i + 1; j < n; j++){
			sum += arr[j];
			result.push_back(sum);
		}
	}
	
	return result;
}

vector<int> input_arr(int n){
	
	vector<int> result(n);
	
	for(int i = 0; i < n; i++){
		cin >> result[i];
	}
	
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	int n;
	cin >> n;
	
	vector<int> arr = input_arr(n);
	vector<int> arr_psum = psum(arr);
	
	int m;
	cin >> m;
	
	vector<int> brr = input_arr(m);
	vector<int> brr_psum = psum(brr);
	
	sort(brr_psum.begin(), brr_psum.end());
	
	long long answer = 0;
	
	for(int x : arr_psum){
		answer += upper_bound(brr_psum.begin(), brr_psum.end(), T - x) - lower_bound(brr_psum.begin(), brr_psum.end(), T - x); 
	}

	cout << answer;
	
	return 0;
}