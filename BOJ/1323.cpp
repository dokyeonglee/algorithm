#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, k;
	cin >> n >> k;
	
	long long digit = 1;
	while(digit <= n){
		digit *= 10;
	}
	
	vector<bool> visited(k, false);
	int answer = 1;
	
	long long r = n % k;
	
	while(r != 0){
		r = (r * digit + n) % k;
		if(visited[r]){
			cout << -1;
			return 0;
		}
		visited[r] = true;
		answer++;
	}
	
	cout << answer;
	
	return 0;
}