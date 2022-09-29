#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& arr, vector<int>& visited, vector<int>& d, int x, int idx){
	if(visited[x] == idx) return false;
	visited[x] = true;
	for(int i = 0; i < arr[x].size(); i++){
		int t = arr[x][i];
		if(visited[t] == idx){
			continue;
		}
		visited[t] = idx;
        if(d[t] == 0 or dfs(arr, visited, d, d[t], idx)){
            d[t] = x;
		    return true;
	    }
    }
	return false;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		int n;
		cin >> n;
		vector<int> height(n + 1);
		vector<char> gender(n + 1);
		vector<string> genre(n + 1);
		vector<string> sports(n + 1);
		vector<int> male, female;

		for(int i = 1; i <= n; i++){
			cin >> height[i] >> gender[i] >> genre[i] >> sports[i];
			if(gender[i] == 'M'){
				male.push_back(i);
			}else{
				female.push_back(i);
			}
		}

		vector<int> visited(n + 1);
		vector<int> d(n + 1);
		
		vector<vector<int>> arr(n + 1);
		for(int i : male){
            for(int j : female){
                if(!(abs(height[i] - height[j]) > 40
                    or genre[i] != genre[j]
                    or sports[i] == sports[j])){
                    arr[i].push_back(j);
                }
            }
		}
		
		int answer = n;
		for(int i = 1; i <= n; i++){
			if(dfs(arr, visited, d, i, i)){
				answer--;
			}
		}
		cout << answer << "\n";
	}
	
	return 0;
}