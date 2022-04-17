#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string str;
	while(cin >> str){
		int answer = 0;
		int pc = 0;
		vector<int> mem(32);
		for(int i = 0; i < 32 and !cin.eof(); i++){
			if(i != 0) cin >> str;
			for(int j = 0; j < str.size(); j++){
				mem[i] = (mem[i] << 1) | (str[j] - '0');
			}
		}
		while(1){
			int command = mem[pc] / 32;
			int x = mem[pc] % 32;
			pc = (pc + 1) & 31;
			if(command == 0){
				mem[x] = answer;
			}else if(command == 1){
				answer = mem[x];
			}else if (command == 2){
				if(answer == 0){
					pc = x;
				}
			}else if(command == 4){
				answer--;
			}else if(command == 5){
				answer++;
			}else if(command == 6){
				pc = x;
			}else if(command == 7){
				break;
			}
			answer &= 255;
		}
		for(int i = 7; i >= 0; i--){
			if(answer & (1 << i)){
				cout << 1;
			}else{
				cout << 0;
			}
		}
		cout << "\n";
	}
	
	return 0;
}