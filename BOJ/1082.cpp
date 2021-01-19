#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> price(n);

	int min_price = 987654321;
	int min_price_idx = -1;

	for(int i = 0; i < n; i++){
		
		cin >> price[i];
		
		if(price[i] <= min_price){
			min_price = price[i];
			min_price_idx = i;
		}
		
	}
	
	int budget;
	cin >> budget;
	
	int max_length = budget / min_price;
	string answer(max_length, '0' + min_price_idx);
	
	budget %= min_price;
	
	int start = 0;
	
	for(int i = 0; i < max_length; i++){
		
		for(int j = n - 1; j >= 0; j--){
			if(price[j] <= budget + min_price){
				answer[i] = '0' + j;
				budget += min_price - price[j];
				break;
			}
		}
		
		if(answer[start] == '0'){
			budget += price[0];
			start++;
		}
	}
	
	if(start == max_length){
		cout << "0" << endl;
	}else{
		cout << answer.substr(start) << endl;
	}

	return 0;
}