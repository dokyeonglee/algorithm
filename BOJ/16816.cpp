#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int s, t, d;
	cin >> s >> t >> d;
	
	vector<long long> psum(d + 1);
	for(int i = 1; i <= d; i++){
		cin >> psum[i];
		psum[i] += psum[i - 1];
		if(s + psum[i] <= t){
			cout << i;
			return 0;
		}
	}
	
	long long answer = 1e18;
	
	if(psum.back() < 0){
		answer = min(answer, (s - t + -psum.back() - 1) / -psum.back() * d);
		for(int i = 1; i < d; i++){
			answer = min(answer, (s - t + psum[i] + -psum.back() - 1) / -psum.back() * d + i);
		}
	}

	if(answer == 1e18){
		answer = -1;
	}
	
	cout << answer;
	
	return 0;
}