#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, h;
	cin >> n >> h;
	
	vector<int> arr(h + 1);
	for(int i = 0; i < n; i++){
		
		int x;
		cin >> x;
		
		if(i % 2 == 0){
			arr[0]++;
			arr[x]--;
		}else{
			arr[h - x]++;
			arr[h]--;
		}
	}
	
	int cnt = 1;
	int min = arr[0];
	
	for(int i = 1; i < h; i++){
		arr[i] += arr[i - 1];
		if(min > arr[i]){
			min = arr[i];
			cnt = 1;
		}else if(min == arr[i]){
			cnt++;
		}
	}
	
	cout << min << " " << cnt;
	
	return 0;
}