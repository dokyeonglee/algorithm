#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	string str;
	cin >> str;
	
	__int128 a = 0;
	for(int i = 0; i < n; i++){
		a = (a << 1) | str[i] - '0';
	}
	
	vector<__int128> switches(m);
	for(int i = 0; i < m; i++){
		cin >> str;
		for(int j = 0; j < n; j++){
			switches[i] = (switches[i] << 1) | (str[j] - '0');
		}
	}
	
	map<int, vector<int>> answer;
	
	for(int i = 0; i < (1 << m); i++){
		__int128 door = a;
		vector<int> result;
		for(int j = 0; j < m; j++){
			if(i & (1 << j)){
				door ^= switches[j];
				result.push_back(j + 1);
			}
		}
		int cnt = 0;
		__int128 temp = door;
		while(temp > 0){
			cnt += temp % 2;
			temp /= 2;
		}
		answer[2 * cnt - n] = result;
	}
		
	for(int i = -n; i <= n; i++){
		if(answer.count(i) == 0){
			cout << -1 << "\n";
		}else{
			cout << answer[i].size() << " ";
			for(int j = 0; j < answer[i].size(); j++){
				cout << answer[i][j] << " ";
			}
			cout << "\n";
		}
	}
	
	return 0;
}