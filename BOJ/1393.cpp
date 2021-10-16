#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
	return b ? gcd(b, a  % b) : a;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int x_s, y_s;
	cin >> x_s >> y_s;
	
	int x_e, y_e, dx, dy;
	cin >> x_e >> y_e >> dx >> dy;
	
	int g = gcd(abs(dx), abs(dy));
	if(g != 0){
		dx /= g;
		dy /= g;
	}
	
	
	int x = x_e;
	int y = y_e;
	
	pair<int, int> answer = make_pair(x, y);
	int dist = 987654321;
	
	while(1){
		if(dist < (x - x_s) * (x - x_s) + (y - y_s) * (y - y_s)){
			break;
		}else{
			answer = make_pair(x, y);
			dist = (x - x_s) * (x - x_s) + (y - y_s) * (y - y_s);
		}
		x += dx;
		y += dy;
	}
	
	cout << answer.first << " " << answer.second;
	
	return 0;
}