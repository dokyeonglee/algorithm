#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, x;
	cin >> n >> x;
	
	x *= 2;
	
	int answer = 0;
	
	vector<long long> serum;
	
	for(int i = 0; i < n; i++){
		long long c;
		cin >> c;
		c *= 2;
		if(c < x){
			serum.push_back(c);
		}else{
			answer++;
		}
	}
	
	sort(serum.begin(), serum.end());
	
	int left = 0;
	int right = serum.size() - 1;
	int cnt = 0;
	
	while(left < right){
		long long sum = serum[left] + serum[right];
		if(sum >= x / 2){
			left++;
			right--;
			answer++;
			cnt += 2;
		}else{
			left++;
		}
	}
	
	cout << answer + (serum.size() - cnt) / 3;
	
	return 0;
}