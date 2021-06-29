#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>>& child, int root, int d){
	
	int result = 0;
	
	if(root == d){
		return result;
	}
	
	if(child[root].size() == 0){
		result++;
	}else if(child[root].size() == 1 and child[root][0] == d){
		result++;
	}else{
		for(int i = 0; i < child[root].size(); i++){
			result += dfs(child, child[root][i], d);
		}
	}
	
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> parent(n);
	vector<vector<int>> child(n);
	
	int root;
	
	for(int i = 0; i < n; i++){
		cin >> parent[i];
		if(parent[i] == -1){
			root = i;
		}else{
			child[parent[i]].push_back(i);
		}
	}
	
	int d;
	cin >> d;
	
	cout << dfs(child, root, d);
	
	return 0;
}