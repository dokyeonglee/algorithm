#include <iostream>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int x = 0;
	
	for(int i = 0; i < n; i++){
		int y;
		cin >> y;
		x ^= y;
	}
	
	if(x == 0){
		cout << "cubelover";
	}else{
		cout << "koosaga";
	}
	
	return 0;
}