#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_perfect_square(long long x){
	long long root = sqrt(x);
	return root * root == x;
}

string solve(string& str){
	
	vector<int> pos;
	for(int i = 0; i < str.size(); i++){
		if(str[i] == '?'){
			pos.push_back(i);
		}
	}
	
	for(int i = 0; i < (1 << pos.size()); i++){
		string temp(str);
		for(int j = 0; j < pos.size(); j++){
			if(i & (1 << j)){
				temp[pos[j]] = '1';
			}else{
				temp[pos[j]] = '0';
			}
		}
		if(is_perfect_square(stoll(temp, nullptr, 2))){
			return temp;
		}
		
	}
	return "-1";
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	for(int i = 1; i <= T; i++){
		string str;
		cin >> str;
		cout << "Case #" << i << ": " << solve(str) << "\n";
	}
	
	return 0;
}