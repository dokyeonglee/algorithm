#include <iostream>
#include <vector>

using namespace std;

int find_parent(vector<int>& parent, int x){
	if(parent[x] == x){
		return x;
	}
	return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, int x, int y){
	x = find_parent(parent, x);
	y = find_parent(parent, y);
    parent[y] = x;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
    vector<vector<int>> arr(n + 1);    
	vector<int> parent(200001);
    vector<int> parent2(200001);
    vector<int> next(200001);

	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
        arr[i].resize(x);
		for(int j = 0; j < x; j++){
			cin >> arr[i][j];
		}
        for(int j = 0; j < x - 1; j++){
            next[arr[i][j]] = arr[i][j + 1];
        }
        for(int j = 0; j < x; j++){
            parent[arr[i][j]] = arr[i][0];
            parent2[arr[i][j]] = arr[i][x - 1];
        }
	}
	
	int q;
	cin >> q;

    vector<string> answer(q);
    vector<pair<int, pair<int, int>>> queries;
	
	for(int i = 0; i < q; i++){
		int command, a, b;
		cin >> command >> a >> b;
		int pa = find_parent(parent, a);
		int pb = find_parent(parent, b);
		if(command == 1){
			if(pa == pb){
                answer[i] = "NO\n";
			}else{
				answer[i] = "YES\n";
                next[find_parent(parent2, a)] = pb;
				union_parent(parent, pa, pb);
                union_parent(parent2, pb, pa);
			}
		}else{
			if(pa == pb){
				queries.push_back(make_pair(i, make_pair(a, b)));
			}else{
                answer[i] = "-1\n";
			}
		}
	}

    vector<int> indices(200001);
    vector<bool> visited(2000001);
    vector<long long> psum(1, 0);

    for(int i = 1; i <= 200000; i++){
        if(!visited[i]){
            int p = find_parent(parent, i);
            for(int v = p; v; v = next[v]){
                psum.push_back(v);
                visited[v] = true;
            }
        }
    }

    for(int i = 1; i < psum.size(); i++){
        indices[psum[i]] = i;
        psum[i] += psum[i - 1];
    }

    for(int i = 0; i < queries.size(); i++){
        int query_idx = queries[i].first;
        int u = queries[i].second.first;
        int v = queries[i].second.second;
        u = indices[u];
        v = indices[v];
        if(u > v){
            swap(u, v);
        }
        answer[query_idx] = to_string(psum[v] - psum[u - 1]) + "\n";
    }

    for(int i = 0; i < q; i++){
        cout << answer[i];
    }
	
	return 0;
}