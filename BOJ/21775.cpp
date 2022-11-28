#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, t;
	cin >> n >> t;
	
	string operators(n + 1, ' ');
	set<int> user;
	
	vector<int> turns(t);
	for(int i = 0; i < t; i++){
		cin >> turns[i];
	}
	
	vector<int> ids(n + 1);
	vector<int> nums(n + 1);
	
	for(int turn : turns){
		string op;
		if(operators[turn] == ' '){
			cin >> ids[turn] >> op;
			operators[turn] = op[0];
			if(op[0] != 'n'){
				cin >> nums[turn];
			}
		}
		switch(operators[turn]){
			case 'r':
				user.erase(nums[turn]);
			case 'n':
				operators[turn] = ' ';	
				break;
			case 'a':
				if(user.count(nums[turn]) == 0){
					operators[turn] = ' ';
					user.insert(nums[turn]);
				}
				break;
		}
		cout << ids[turn] << "\n";
	}
	
	
	return 0;
}