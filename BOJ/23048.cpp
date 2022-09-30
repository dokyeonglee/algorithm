#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int color = 1;
	
	vector<int> arr(n + 1);
	arr[1] = color++;
	
	for(int i = 2; i <= n; i++){
		if(arr[i] == 0){
			for(int j = i; j <= n; j += i){
				arr[j] = color;
			}
			color++;
		}
	}
	
	cout << color - 1 << "\n";
	for(int i = 1; i <= n; i++){
		cout << arr[i] << " ";
	}
	
	
	return 0;
}