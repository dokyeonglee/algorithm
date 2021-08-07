#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, c;
	cin >> n >> c;
	
	vector<long long> arr(n);
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	vector<long long> left;
	vector<long long> right;
	
	for(int i = 0; i < (1 << (n / 2)); i++){
		
		long long sum = 0;
		
		for(int j = 0; j < n / 2; j++){
			if(i & (1 << j)){
				sum += arr[j];	
			}
		}
		
		if(sum != 0 and sum <= c){
			left.push_back(sum);	
		}
		
	}
	
	for(int i = (1 << (n / 2)); i < (1 << n); i += (1 << (n / 2))){
		
		long long sum = 0;
		
		for(int j = n / 2; j < n; j++){
			if(i & (1 << j)){
				sum += arr[j];	
			}
		}
		
		if(sum != 0 and sum <= c){
			right.push_back(sum);	
		}
		
	}
	
	sort(right.begin(), right.end());
	
	long long answer = left.size() + right.size();
	
	for(int i = 0; i < left.size(); i++){
		answer += upper_bound(right.begin(), right.end(), c - left[i]) - right.begin();
	}
	
	cout << answer + 1;
		
	return 0;
}