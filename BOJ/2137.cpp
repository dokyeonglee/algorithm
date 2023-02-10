#include <iostream>
using namespace std;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int main() {
	
	long long x, y;
	cin >> x >> y;
	
	pair<long long, long long> answer;
	int cnt = 0;
	for(int i = 2; i <= 32767; i++){
		for(int j = 1; j < i; j++){
			if(i * x == j * y){
				continue;
			}
			if(answer.first == 0){
				answer = make_pair(j, i);
			}else{
				long long diff1 = abs(x * answer.second * i - answer.first * y * i);
				long long diff2 = abs(x * answer.second * i - answer.second * y * j);
				if(diff1 > diff2){
					answer = make_pair(j, i);
				}else if(diff1 == diff2){
					if(answer.first * i  > j * answer.second){
						answer = make_pair(j, i);
					}
				}
			}
		}
	}
	
	int g = gcd(answer.first, answer.second);
	cout << answer.first / g << " " << answer.second / g;
	
	return 0;
}