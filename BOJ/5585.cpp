#include <iostream>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int coin[] = {500, 100, 50 ,10 ,5, 1};
	
	int n;
	cin >> n;
	
	n = 1000 - n;
	
	int answer = 0;
	int idx = 0;
	while(n > 0){
		answer += n / coin[idx]; 
		n %= coin[idx++];
	}
	
	cout << answer;
	
	return 0;
}