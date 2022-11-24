#include <iostream>
#include <queue>

using namespace std;

int d[] = {1, -1, 5, -5};

bool check(int board){

	int x = board & -board;
	board &= ~x;

	queue<int> q;
	q.push(x);

	while(!q.empty()){
		
		int now = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++){
			if((i == 0 and (now & 0x1084210)) or (i == 1 and (now & 0x0108421))){
				continue;
			}
			int next;
			if(i % 2 == 0){
				next = (now << d[i]);
			}else{
				next = (now >> d[i - 1]);
			}
			if(next <= 0 or next >= (1 << 25) or (board & next) == 0){
				continue;
			}
			board &= ~next;
			q.push(next);
		}
	}
	
	return board == 0;
}

int bfs(int board){
	
	vector<bool> visited(1 << 25);
	visited[board] = true;
	
	queue<pair<int, int>> q;
	q.push(make_pair(0, board));
	
	while(!q.empty()){
		
		int cnt = q.front().first;
		int now = q.front().second;
		q.pop();
		
		if(check(now)){
			return cnt;
		}
		
		for(int i = now; i; i &= (i - 1)){
			for(int j = 0; j < 4; j++){
				if((j == 0 and ((i & -i) & 0x1084210)) or (j == 1 and ((i & -i) & 0x0108421))){
					continue;
				}
				int next;
				if(j % 2 == 0){
					next = ((i & -i) << d[j]);
				}else{
					next = ((i & -i) >> d[j - 1]);
				}
				if(next <= 0 or next >= (1 << 25) or (now & next) == next){
					continue;
				}
				next |= (now & ~(i & -i));
				if(!visited[next]){
					visited[next] = true;
					q.push(make_pair(cnt + 1, next));
				}
			}
		}
	}
	
	return -1;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int board = 0;
	for(int i = 0; i < 5; i++){
		string str;
		cin >> str;
		int temp = 0;
		for(int j = 0; j < 5; j++){
			if(str[j] == '*'){
				temp |= (1 << (4 - j));
			}
		}
		board = (board << 5) | temp;
	}
	
	cout << bfs(board);
	
	return 0;
}