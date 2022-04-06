#include <iostream>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		string _x;
		cin >> _x;
		int x = stoi(_x, 0, 16);
		if(x >= 64 and x <= 95){
			cout << "-";
		}else{
			cout << ".";
		}
	}
	
	return 0;
}