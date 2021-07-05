#include <iostream>
#include <vector>

using namespace std;

int get_level(vector<int>& parent, int v){
	
	int result = 0;
	int now = v;
	
	while(now != 0){
		result++;
		now = parent[now];
	}
	
	return result;
	
}

int solve(vector<int>& parent, int a, int a_level, int b, int b_level){
	
	if(a_level > b_level){
		while(a_level != b_level){
			a_level--;
			a = parent[a];
		}
	}else if(a_level < b_level){
		while(a_level != b_level){
			b_level--;
			b = parent[b];
		}
	}
	
	while(a != b){
		a = parent[a];
		b = parent[b];
	}
	
	return a;
	
}


int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		
		int n;
		cin >> n;
		
		vector<int> parent(n + 1);
		
		int u, v;
		
		for(int i = 1; i < n; i++){
			cin >> u >> v;
			parent[v] = u;
		}
		
		cin >> u >> v;
		
		int u_level = get_level(parent, u);
		int v_level = get_level(parent, v);
		
		cout << solve(parent, u, u_level, v, v_level) << "\n";
	}
	
	return 0;
}