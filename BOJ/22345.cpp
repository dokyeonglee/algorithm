#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	vector<pair<int, int>> arr(n + 2);
	arr.front() = make_pair(-1e9 - 1, 0);
	arr.back() = make_pair(1e9 + 1, 0);

	for(int i = 1 ; i <= n; i++){
		cin >> arr[i].second >> arr[i].first;
	}
	
	sort(arr.begin(), arr.end());
	
	vector<long long> cnt_left_to_right(n + 2);
	vector<long long> cnt_right_to_left(n + 2);
	
	cnt_left_to_right[1] = arr[1].second;
	cnt_right_to_left[n] = arr[n].second;
	
	vector<long long> psum_left_to_right(n + 2);
	vector<long long> psum_right_to_left(n + 2);
	
	for(int i = 2; i <= n; i++){
		psum_left_to_right[i] = psum_left_to_right[i - 1] + (arr[i].first - arr[i - 1].first) * cnt_left_to_right[i - 1];
		cnt_left_to_right[i] = cnt_left_to_right[i - 1] + arr[i].second;
	}

	for(int i = n - 1; i >= 1; i--){
		psum_right_to_left[i] = psum_right_to_left[i + 1] + (arr[i + 1].first - arr[i].first) * cnt_right_to_left[i + 1];
		cnt_right_to_left[i] = cnt_right_to_left[i + 1] + arr[i].second;
	}
	
	int candidate;
	for(int i = 0; i < q; i++){
	
		cin >> candidate;
		auto it = lower_bound(arr.begin(), arr.end(), make_pair(candidate, 0));
		int idx = it - arr.begin();
		
		if(candidate == it->first){
			cout << psum_left_to_right[idx] + psum_right_to_left[idx] << "\n";
		}else{
			cout << psum_left_to_right[idx - 1] + psum_right_to_left[idx] 
			+ (candidate - arr[idx - 1].first) * cnt_left_to_right[idx - 1]
			+ (arr[idx].first - candidate) * cnt_right_to_left[idx] << "\n";
		}
	}
	
	
	return 0;
}