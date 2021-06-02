#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const string command = "DSLR";

string bfs(int A, int B){
	
	vector<bool> visited(10000, false);
	visited[A] = true;
	
	queue<pair<int, string>> q;
	q.push(make_pair(A, ""));
	
	string result = "";
	
	while(!q.empty()){
		
		int now = q.front().first;
		string path = q.front().second;
		q.pop();
		
		if(now == B){
			result = path;
			break;
		}
		
		int D = now * 2 % 10000;
		int S = (now - 1 + 10000) % 10000;
		int L = (now * 10 + now / 1000) % 10000;
		int R = now % 10 * 1000 + now / 10;
		int next[] = {D, S, L, R};
		
		for(int i = 0; i < 4; i++){
			if(!visited[next[i]]){
				visited[next[i]] = true;
				q.push(make_pair(next[i], path + command[i]));
			}
		}
	}
	
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		
		int A, B;
		cin >> A >> B;
		
		cout << bfs(A, B) << "\n";
		
	}
	
	return 0;
}