#include <iostream>
#include <vector>

using namespace std;

int num_key_move(vector<bool>& is_broken, int n){
	if(n == 0){
		if(is_broken[0]){
			return 0;
		}else{
			return 1;
		}
	}
	
	int result = 0;
	
	while(n > 0){
		if(is_broken[n % 10]){
			return 0;
		}
		n /= 10;
		result++;
	}
	
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int m;
	cin >> m;
	
	vector<bool> is_broken(10, false);
	
	for(int i = 0; i < m; i++){
		int num;
		cin >> num;
		is_broken[num] = true;
	}
	
	int answer = abs(n - 100);
	for(int i = 0; i <= 1111111; i++){
		int len = num_key_move(is_broken, i);
		if(len > 0){
			answer = min(answer, len + abs(i - n));
		}
	}

	cout << answer;
	
	return 0;
}