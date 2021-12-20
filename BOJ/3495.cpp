#include <iostream>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int r, c;
	cin >> r >> c;
	
	int answer = 0;
	
	for(int i = 0; i < r; i++){
		string str;
		cin >> str;
		int cnt = 0;
		for(int j = 0; j < c; j++){
			if(str[j] == '.' and cnt % 2 == 1){
				answer += 2;
			}else if(str[j] != '.'){
				answer += 1;
				cnt++;
			}
		}	
	}
	
	cout << answer / 2;
	
	return 0;
}