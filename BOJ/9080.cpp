#include <iostream>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		
		string str;
		cin >> str;
		
		int hour = ((str[0] - '0') * 10 + (str[1] - '0') + 2) % 24;
		int minute = (str[3] - '0') * 10 + (str[4] - '0');
		
		int time;
		cin >> time;
		
		int answer = 0;
		while(time > 0){
			if(hour < 5 and time >= 300){
				time -= 600 - hour * 60 - minute;
				hour = 10;
				minute = 0;
				answer += 5000;
			}else{
				hour = (hour + 1) % 24;
				time -= 60;
				answer += 1000;
			}
		}
		
		cout << answer << "\n";
	}
	
	return 0;
}