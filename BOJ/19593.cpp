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

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        long long seed, a, b;
        cin >> seed >> a >> b;

        vector<int> parent(n + 1);

        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }

        long long e = seed % (n * n);

        vector<bool> visited(n * n);

        int answer = 0;
        int cnt = 1;

        while(cnt < n){
            long long x = e / n;
            long long y = e % n;
            if(visited[e]){
                break;
            }
            visited[e] = true;
            if(find_parent(parent, x) != find_parent(parent, y)){
                cnt++;
                union_parent(parent, x, y);
            }
            answer++;
            e = (e * a + b) % (n * n);
        }

        if(cnt != n){
            answer = 0;
        }

        cout << answer << "\n";

    }

    return 0;
}