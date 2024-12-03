#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> cnt(n + 1);

    while(m--){
        int u, v;
        cin >> u >> v;
        if(u < v){
            swap(u, v);
        }
        cnt[u]++;
    }

    string answer(n - 1, 'N');

    for(int i = 2; i <= n; i++){
        if(cnt[i] == i - 1){
            answer[i - 2] = 'E';
        }else if(cnt[i]){
            cout << -1;
            return 0;
        }
    }

    cout << answer;

    return 0;
}