#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> arr(10);
	for(int i = 0; i < 10; i++){
		arr[i] = i;
	}
	
	int n;
	cin >> n;
	
	do{
		int h = arr[0];
		int e = arr[1];
		int l = arr[2];
		int o = arr[3];
		int w = arr[4];
		int r = arr[5];
		int d = arr[6];
		
		int hello = h * 10000 + e * 1000 + l * 100 + l * 10 + o;
		int world = w * 10000 + o * 1000 + r * 100 + l * 10 + d;
		
		if(hello + world == n && h != 0 && w != 0){
			cout << "  " << hello << "\n";
			cout << "+ " << world << "\n";
			cout << "-------\n";
			cout.width(7);
			cout << n;
			return 0;
		}
		
	}while(next_permutation(arr.begin(), arr.end()));
	
	cout << "No Answer";
	
	return 0;
}