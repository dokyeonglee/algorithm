#include <iostream>
#include <queue>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		
		int n;
		cin >> n;
		
		vector<long long> file_size(n);
		for(int i = 0; i < n; i++){
			cin >> file_size[i];
			file_size[i] = -file_size[i];
		}
		
		priority_queue<long long> pq(file_size.begin(), file_size.end());
		
		long long answer = 0;
		long long x, y;
		
		while(pq.size() > 1){
			
			x = -pq.top();
			pq.pop();
			
			y = -pq.top();
			pq.pop();
			
			answer += x + y;
			pq.push(-(x + y));
			
		}
		
		cout << answer << "\n";
		
	}
	
	return 0;
}