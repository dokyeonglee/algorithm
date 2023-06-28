#include <iostream>
#include <vector>

using namespace std;

int find_parent(vector<int>& parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, vector<long long>& sum, vector<long long>& square_sum, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    sum[x] += sum[y];
    square_sum[x] += square_sum[y];
    parent[y] = x;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> parent(n + 1);
    vector<long long> sum(n + 1);
    vector<long long> square_sum(n + 1);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    for(int i = 1; i <= n; i++){
        cin >> sum[i];
        square_sum[i] = sum[i] * sum[i];
    }

    while(q--){
        int a, b;
        cin >> a >> b;
        a = find_parent(parent, a);
        b = find_parent(parent, b);
        if(a != b){
            union_parent(parent, sum, square_sum, a, b);
        }
        cout << (sum[a] * sum[a] - square_sum[a]) / 2 << "\n";
    }

    return 0;
}