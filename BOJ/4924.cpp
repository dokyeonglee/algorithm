#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<bool> is_prime(1e6 + 1, true);
	is_prime[0] = false;
	is_prime[1] = false;
	
	for(int i = 2; i * i <= 1e6; i++){
		if(is_prime[i]){
			for(int j = i * i; j <= 1e6; j += i){
				is_prime[j] = false;
			}
		}
	}
	
	vector<long long> arr(1e6 + 1);
	for(int i = 2; i <= 1e6; i++){
		if(is_prime[i]){
			arr[i] = -1;
		}else{
			int temp = i;
			for(int j = 2; j * j <= temp; j++){
				while(temp % j == 0){
					temp /= j;
					arr[i]++;
				}
			}
			if(temp > 1){
				arr[i]++;
			}
		}
	}
	
	for(int i = 1; i <= 1e6; i++){
		arr[i] += arr[i - 1];
	}
	
	for(int i = 1; i <= 1e6; i++){
		arr[i] -= i;
	}
	
	int t = 1;
	
	while(1){
		int l, u;
		cin >> l >> u;
		if(l == -1){
			break;
		}
		long long answer = -1e18;
		long long temp = 0;
		for(int i = l; i <= u; i++){
			temp += + arr[i] - arr[i - 1];
			answer = max(answer, temp);
			if(temp < 0){
				temp = 0;
			}
		}
		cout << t++ << ". " << answer << "\n";
	}
	
	
	return 0;
}