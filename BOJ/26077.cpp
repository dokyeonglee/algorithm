#include <iostream>
#include <vector>

using namespace std;

int find_parent(vector<int>& parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, vector<int>& sz, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    if(x != y){
        sz[x] += sz[y];
        parent[y] = x;
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> min_prime_factor(1e6 + 1);
    for(int i = 1; i <= 1e6; i++){
        min_prime_factor[i] = i;
    }

    for(int i = 2; i * i <= 1e6; i++){
        if(min_prime_factor[i] == i){
            for(int j = i * i; j <= 1e6; j += i){
                min_prime_factor[j] = i;
            }
        }
    }

    int n;
    cin >> n;

    vector<int> parent(1e6 + 1);
    vector<int> sz(1e6 + 1);
    vector<int> id(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> id[i];
        sz[id[i]]++;
    }

    
    for(int i = 1; i <= 1e6; i++){
        parent[i] = i;
    }

    for(int i = 1; i <= n; i++){
        int temp = id[i];
        while(temp > 1){
            union_parent(parent, sz, min_prime_factor[temp], id[i]);
            temp /= min_prime_factor[temp];
        }
    }

    int answer = 0;

    for(int i = 1; i <= 1e6; i++){
        answer = max(answer, sz[i]);
    }

    cout << answer;

    return 0;
}