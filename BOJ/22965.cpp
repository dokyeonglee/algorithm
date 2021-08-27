#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> arr(n);
	int min_value = 200001;
	int min_index = 0;
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		if(min_value > arr[i]){
			min_value = arr[i];
			min_index = i;
		}
	}
	
	bool check = true;
	
	for(int i = 0; i < n - 1; i++){
		if(arr[(min_index + i) % n] > arr[(min_index + i + 1) % n]){
			check = false;
			break;
		}	
	}
	
	if(check){
		if(min_index == 0){
			cout << 1;
		}else{
			cout << 2;
		}
	}else{
		cout << 3;
	}
	
	return 0;

}