#include <iostream>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int answer = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x % 4 == 3){
			x++;
		}else if(x % 4 == 0){
			x--;
		}
		answer ^= x;
	}
	
	if(answer){
		cout << "koosaga";
	}else{
		cout << "cubelover";
	}
	
	return 0;
}