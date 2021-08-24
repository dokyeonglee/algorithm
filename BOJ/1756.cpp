#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int d, n;
	cin >> d >> n;
	
	vector<int> depth(d + 1);
	depth[0] = 1987654321;
	
	for(int i = 1; i <= d; i++){
		cin >> depth[i];
		depth[i] = min(depth[i], depth[i - 1]);
	}
	
	int pizza;
	int pos = d;
	
	for(int i = 0; i < n; i++){
		cin >> pizza;
		while(pos > 0 and depth[pos] < pizza){
			pos--;
		}
		pos--;
	}
	cout << max(pos + 1, 0);
	
	return 0;
}