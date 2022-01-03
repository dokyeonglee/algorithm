#include <iostream>
#include <vector>
#include <set>

using namespace std;

int max_xor(vector<int>& arr){
	
	int result = 0;
	int bit = 0;
	set<int> s;
	
	for(int i = 30; i >= 0; i--){
		bit |= 1 << i;
		for(int i = 0; i < arr.size(); i++){
			s.insert(arr[i] & bit);
		}
		int temp = result | (1 << i);
		for(int x : s){
			if(s.count(temp ^ x)){
				result = temp;
				break;
			}
		}
		s.clear();
	}
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	cout << max_xor(arr);
	
	return 0;
}