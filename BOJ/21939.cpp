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
	map<int, int> difficulty;
	
	for(int i = 0; i < n; i++){
		int p, l;
		cin >> p >> l;
		hard.push(make_pair(l, p));
		easy.push(make_pair(-l, -p));
		difficulty[p] = l;
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
			difficulty[p] = l;
			
		}else if(command == "solved"){
			
			int p;
			cin >> p;

			difficulty[p] = -1;
			
		}else{
			
			int x;
			cin >> x;
			
			if(x == 1){
				
				while(!hard.empty() and difficulty[hard.top().second] == -1){
					hard.pop();
				}
				
				if(hard.top().first != difficulty[hard.top().second]){
					pair<int, int> temp = hard.top();
					hard.pop();
					temp.first = difficulty[temp.second];
					hard.push(temp);
				}
				
				cout << hard.top().second << "\n";
				
			}else{
				
				while(!easy.empty() and difficulty[-easy.top().second] == -1){
					easy.pop();
				}
				
				if(-easy.top().first != difficulty[-easy.top().second]){
					pair<int, int> temp = easy.top();
					easy.pop();
					temp.first = -difficulty[-temp.second];
					easy.push(temp);
				}
				
				cout << -easy.top().second << "\n";
				
			}
		}
	}
	
	return 0;
}