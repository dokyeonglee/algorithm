#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> degree(n + 1);

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }

    for(int i = 1; i <= n; i++){
        if(degree[i] == n - 1){
            cout << n - 1;
            return 0;
        }
    }

    cout << n;

    return 0;
}