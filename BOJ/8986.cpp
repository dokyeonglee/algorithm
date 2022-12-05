#include <iostream>
#include <vector>

using namespace std;

long long move_cnt(vector<int>& arr, long long d){
	long long cnt = 0;
	for(int i = 0; i < arr.size(); i++){
		cnt += abs(arr[i] - i * d);
	}
	return cnt;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	long long left = 0;
	long long right = arr.back() + 1;
	
	for(int i = 0; i < 100; i++){
		long long p1 = (2 * left + right) / 3;
		long long p2 = (left + 2 * right) / 3;
		if(move_cnt(arr, p1) < move_cnt(arr, p2)){
			right = p2;
		}else{
			left = p1;
		}
	}
	
	cout << move_cnt(arr, (left + 2 * right) / 3);
	
	return 0;
}