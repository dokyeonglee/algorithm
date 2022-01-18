#include <iostream>
#include <cmath>

using namespace std;

int main() {
	
	int s, p;
	cin >> s >> p;
	
	int answer = 2;
	double prev = 0;
	
	if(s == p){
		answer = 1;
	}else{
		while(1){
			double temp = pow((double)s / answer, answer);
			if(temp >= p){
				break;
			}else if(temp < prev){
				answer = -1;
				break;
			}
			prev = temp;
			answer++;
		}
	}
	
	cout << answer;
	
	return 0;
}