#include <iostream>
#include <vector>

using namespace std;

long long power_of_ten[11] = {1};

long long solve(string x){
	if(x == "0"){
		return 0;
	}
	long long result = 0;
	for(int i = 0; i < x.size(); i++){
		int d = x[i] - '0';
		result += d * power_of_ten[x.size() - i - 1] / 10 * (x.size() - i - 1) * 45;
		if(i < x.size() - 1){
			result += d * (stoll(x.substr(i + 1)) + 1) + d * (d - 1) / 2 * power_of_ten[x.size() - i - 1];
		}else{
			result += d * (d + 1) / 2;
		}
	}
	return result;
}

int digit_sum(string x){
	int result = 0;
	for(int i = 0; i < x.size(); i++){
		result += x[i] - '0';
	}
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for(int i = 1; i <= 10; i++){
		power_of_ten[i] = power_of_ten[i - 1] * 10;
	}

	string l, u;
	cin >> l >> u;

	cout << solve(u) - solve(l) + digit_sum(l);
	
	return 0;
}