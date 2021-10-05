#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	int s;
	cin >> s;
	
	for(int i = 0; i < n; i++){
		
		if(s == 0){
			break;
		}
		
		int max = -1;
		int pos = 0;
		
		for(int j = i; j <= i + s and j < n; j++){
			if(arr[j] > max){
				max = arr[j];
				pos = j;
			}
		}
		
		for(int j = pos; j > i; j--){
			s--;
			swap(arr[j], arr[j - 1]);
		}
		
	}
	
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	
	return 0;
}