#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> bfs(int n, vector<int>& v){

    vector<int> visited(n + 1, -1);
	
    queue<int> q;
    q.push(n);

	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(now == 0){
			return visited;
		}
		for(int i = 0; v[i] <= now; i++){
            int next = now - v[i];
			if(visited[next] == -1){
				visited[next] = now;
				q.push(next);
			}
		}
	}

	return {-1};
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> v = {4, 7};

	v.reserve(200);

	int left = 0;
	int right = 1;
	for(int i = 0; i < 6; i++){
		for(int j = left; j <= right; j++){
			v.push_back(v[j] * 10 + 4);
			v.push_back(v[j] * 10 + 7);
		}
		left += 1 << (i + 1);
		right = 2 * left + 1;
	}
	
	sort(v.begin(), v.end());
	
	int n;
	cin >> n;
	
	vector<int> result = bfs(n, v);

    if(result.size() == 1){
        cout << -1;
        return 0;
    }


    int r = 0;
    stack<int> answer;

	while(r != n){
        answer.push(result[r] - r);
        r = result[r];
    }

    while(!answer.empty()){
        cout << answer.top() << " ";
        answer.pop();
    }
	
	return 0;
}