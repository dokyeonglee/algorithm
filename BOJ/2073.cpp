#include <iostream>
#include <vector>

using namespace std;

int find_parent(vector<int>& parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, vector<int>& sz, vector<int>& candy, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    parent[y] = x;
    sz[x] += sz[y];
    candy[x] += candy[y];
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int d, p;
    cin >> d >> p;

    vector<int> l(p);
    vector<int> c(p);

    for(int i = 0; i < p; i++){
        cin >> l[i] >> c[i];
    }

    vector<int> dp(d + 1);
    dp[0] = 987654321;
    
    for(int i = 1; i <= p; i++){
        for(int j = d; j >= l[i - 1]; j--){
            dp[j] = max(dp[j], min(dp[j - l[i - 1]], c[i - 1]));
        }
    }

    cout << dp[d];

    return 0;
}