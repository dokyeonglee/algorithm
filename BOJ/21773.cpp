#include <iostream>
#include <queue>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T, n;
	cin >> T >> n;
	
	priority_queue<pair<pair<int, int>, int>> pq;
	for(int i = 0; i < n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		pq.push(make_pair(make_pair(c, -a), b));
	}
	
	while(T--){
		cout << -pq.top().first.second << "\n";
		auto temp = pq.top();
		pq.pop();
		temp.first.first--;
		temp.second--;
		if(temp.second > 0){
			pq.push(temp);	
		}
	}
	
	return 0;
}