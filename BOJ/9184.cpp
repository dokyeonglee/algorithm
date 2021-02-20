#include <iostream>
using namespace std;

int mem[21][21][21];

int w(int a, int b, int c){
	
	if(a <= 0 or b <= 0 or c <= 0){
		return 1;
	}
	
	if(a > 20 or b > 20 or c > 20){
		return w(20, 20, 20);
	}
	
	if(mem[a][b][c] != 0){
		return mem[a][b][c];
	}
	
	if(a < b and b < c){
		return mem[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}else{
		return mem[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b, c;
	while(1){
		cin >> a >> b >> c;
		if(a == -1 and b == -1 and c == -1){
			break;
		}
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
	}
	
	return 0;
}