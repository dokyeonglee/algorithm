#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
	priority_queue<int, vector<int>, greater<int>> usable_computer;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> using_computer;
	
	for(int i = 1; i <= n; i++){
		int p, q;
		cin >> p >> q;
		pq.push(make_pair(p, q));
		usable_computer.push(i);
	}
	
	int answer = 0;
	vector<int> cnt(n + 1);
	
	while(!pq.empty()){
		
		pair<int, int> p = pq.top();
		pq.pop();
		
		while(!using_computer.empty() and p.first > using_computer.top().first){
			usable_computer.push(using_computer.top().second);
			using_computer.pop();
		}
		
		int com = usable_computer.top();
		usable_computer.pop();
		
		cnt[com]++;
		
		answer = max(answer, com);
		using_computer.push(make_pair(p.second, com));
		
	}
	
	cout << answer << '\n';
	for(int i = 1; i <= answer; i++){
		cout << cnt[i] << " ";
	}
	
	return 0;
}