#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	priority_queue<pair<int, int>> hard, easy;
	map<int, int> solved;
	
	for(int i = 0; i < n; i++){
		int p, l;
		cin >> p >> l;
		hard.push(make_pair(l, p));
		easy.push(make_pair(-l, -p));
	}
	
	int m;
	cin >> m;
	
	for(int i = 0; i < m; i++){
		
		string command;
		cin >> command;
		
		if(command == "add"){
			
			int l, p;
			cin >> p >> l;
			
			hard.push(make_pair(l, p));
			easy.push(make_pair(-l, -p));
			
		}else if(command == "solved"){
			
			int p;
			cin >> p;

			solved[p] = 1;
			
		}else{
			
			int x;
			cin >> x;
			
			if(x == 1){
				
				while(!hard.empty() and solved[hard.top().second] == 1){
					hard.pop();
				}
				
				cout << hard.top().second << "\n";
				
			}else{
				
				while(!easy.empty() and solved[-easy.top().second] == 1){
					easy.pop();
				}
				
				cout << -easy.top().second << "\n";
				
			}
		}
	}
	
	return 0;
}