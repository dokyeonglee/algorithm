#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<bool> is_prime(1e6 + 1, true);
	is_prime[0] = is_prime[1] = false;
	
	for(int i = 2; i * i <= 1e6; i++){
		if(is_prime[i]){
			for(int j = i * i; j <= 1e6; j += i){
				is_prime[j] = false;
			}
		}
	}
	
	int n;
	cin >> n;
	
	for(int i = 2; i <= n; i++){
		if(is_prime[i]){
			vector<bool> visited(1e3, false);
			int temp = i;
			while(1){
				int sum = 0;
				while(temp > 0){
					sum += (temp % 10) * (temp % 10);
					temp /= 10;
				}
				if(sum == 1){
					cout << i << "\n";
					break;
				}
				if(visited[sum]){
					break;
				}else{
					visited[sum] = true;
				}
				temp = sum;
			}
		}
	}
	
	return 0;
}