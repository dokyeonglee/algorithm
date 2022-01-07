#include <iostream>
#include <vector>

using namespace std;

long long sqrFree(vector<long long> mu, long long n){
	long long cnt = 0;
	for(long long i = 1; i * i <= n; i++){
		cnt += mu[i] * (n / (i * i));
	}
	return cnt;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<long long> mu(1000001);
	mu[1] = 1;
	for(int i = 1; i <= 1000000; i++){
		for(int j = 2 * i; j <= 1000000; j += i){
			mu[j] -= mu[i];
		}
	}
	
	long long k;
	cin >> k;
	
	long long left = 0;
	long long right = 1e12;
	long long answer = 0;
	
	while(left <= right){
		long long mid = (left + right) / 2;
		long long cnt = sqrFree(mu, mid);
		if(cnt >= k){
			answer = mid;
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
	
	cout << answer;
		
	return 0;
}