#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	map<int, int> arr;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		for(int j = 2; j * j <= x; j++){
			while(x % j == 0){
				arr[j]++;
				x /= j;
			}
		}
		if(x > 1){
			arr[x]++;
		}
	}
	
	int m;
	cin >> m;
	
	map<int, int> brr;
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		for(int j = 2; j * j <= x; j++){
			while(x % j == 0){
				brr[j]++;
				x /= j;
			}
		}
		if(x > 1){
			brr[x]++;
		}
	}
	
	long long answer = 1;
	bool zero_padding = false;
	
	for(auto it : arr){
		int cnt = min(it.second, brr[it.first]);
		for(int i = 0; i < cnt; i++){
			answer *= it.first;
			if(answer >= 1e9){
				zero_padding = true;
			}
			answer %= 1000000000;
		}
	}
	
	if(zero_padding){
		cout.width(9);
		cout.fill('0');
		cout << answer;
	}else{
		cout << answer;
	}
	
	return 0;
}