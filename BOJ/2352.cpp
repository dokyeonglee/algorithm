#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int n;
	cin >> n;
 
	vector<int> vt(1, -1);
 
	for(int i = 0; i < n; i++){
 
		int x;
		cin >> x;
 
		if(vt.back() < x){
			vt.push_back(x);
		}else{
			auto it = lower_bound(vt.begin(), vt.end(), x);
			*it = x;
		}
 
	}
 
	cout << vt.size() - 1;
 
	return 0;
}