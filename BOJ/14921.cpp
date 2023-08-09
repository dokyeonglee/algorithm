#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sum_of_two_value(vector<int>& liquid){

	int lo = 0;
	int hi = liquid.size() - 1;
	int min_value = 200000001;
	
	while(lo < hi){
		if(abs(liquid[lo] + liquid[hi]) < abs(min_value)){
			min_value = liquid[lo] + liquid[hi];	
		}
		if(liquid[lo] + liquid[hi] < 0){
			lo++;
		}else{
			hi--;
		}
	}
	
	return min_value;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> liquid(n);
	for(int i = 0; i < n; i++){
		cin >> liquid[i];
	}
	
	cout << sum_of_two_value(liquid);
	
	return 0;
	
}
