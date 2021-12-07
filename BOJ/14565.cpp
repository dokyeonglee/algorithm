#include <iostream>
#include <vector>

using namespace std;

pair<long long, pair<long long, long long>> mod_inv(long long a, long long b){
	if(b == 0){
		return make_pair(a, make_pair(1, 0));
	}
	auto result = mod_inv(b, a % b);
	return make_pair(result.first, make_pair(result.second.second, result.second.first - (a / b) * result.second.second));
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, a;
	cin >> n >> a;
	
	cout << n - a << " ";
	
	auto answer = mod_inv(a, n);
	if(answer.first != 1){
		cout << -1;
	}else{
		cout << (answer.second.first + n) % n;
	}
	
	return 0;
}