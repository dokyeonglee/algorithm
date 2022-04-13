#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		sort(str.begin(), str.end());
		do{
			cout << str << "\n";
		}while(next_permutation(str.begin(), str.end()));
	}
	
	return 0;
}