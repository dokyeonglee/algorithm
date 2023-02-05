#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int turn_off(int lights, int n){
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(lights & (1 << i)){
			cnt++;
		}else{
            if(cnt >= 4){
			    lights &= ~(((1 << cnt) - 1) << (i - cnt));
		    }
            cnt = 0;
        }
	}
	if(cnt >= 4){
		lights &= ~(((1 << cnt) - 1) << (n - cnt));
	}
	return lights;
}

int bfs(int lights, int n){
	
	vector<bool> visited(1 << n);
	visited[lights] = true;
	
	queue<pair<int, int>> q;
	q.push(make_pair(0, lights));
	
	while(!q.empty()){

		int cnt = q.front().first;
		int now = q.front().second;
        q.pop();

		if(now == 0){
			return cnt;
		}

        int idx = 0;
        for(int i = 0; i < n; i++){
            if(now & (1 << i)){
                idx = i;
                break;
            }
        }

        if(n - idx < 3){
            idx = max(0, idx - 3);
        }
        
		for(int i = idx; i < n; i++){
			if((now & (1 << i)) == 0){
				int next = now | (1 << i);
				next = turn_off(next, n);
				if(!visited[next]){
					visited[next] = true;
					q.push(make_pair(cnt + 1, next));
				}
			}
		}
	}
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int lights = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		lights |= (1 << i) * x;
	}

	cout << bfs(lights, n);
	
	return 0;
}