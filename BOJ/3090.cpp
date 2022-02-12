#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long N, T;
	cin >> N >> T;
	
	vector<long long> arr(N);
	
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	
	int left = 0;
	int right = 1e9;
	vector<long long> answer;
	
	while(left <= right){
		int mid = (left + right) / 2;
		bool possible;
		long long cnt = 0;
		
		vector<long long> temp(arr);
		
		for(int i = 0; i < N - 1; i++){
			if(temp[i + 1] - temp[i] > mid){
				cnt += temp[i + 1] - temp[i] - mid;
				temp[i + 1] = temp[i] + mid;
			}
		}
		
		for(int i = N - 2; i >= 0; i--){
			if(temp[i] - temp[i + 1] > mid){
				cnt += temp[i] - temp[i + 1] - mid;
				temp[i] = temp[i + 1] + mid;
			}
		}
		
		possible = (cnt <= T);
		
		if(possible){
			right = mid - 1;
			answer = temp;
		}else{
			left = mid + 1;
		}
	}
	
	for(int i = 0; i < N; i++){
		cout << answer[i] << " ";
	}
	
	return 0;
}