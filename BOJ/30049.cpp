#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> sales(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < k; j++){
            int x, y;
            cin >> x >> y;
            sales[i][x] = y;
        }
    }

    vector<int> cnt(n + 1);
    vector<int> king(m + 1);

    for(int i = 1; i <= m; i++){
        int max_sale = 0;
        for(int j = 1; j <= n; j++){
            if(max_sale < sales[j][i]){
                max_sale = sales[j][i];
                king[i] = j;
            }
        }
        cnt[king[i]]++;
    }

    int answer = 0;

    for(int i = 1; i <= n; i++){
        if(cnt[i] == k){
            answer++;
        }
    }

    int q;
    cin >> q;

    while(q--){

        int i, j, v;
        cin >> i >> j >> v;

        if(king[j] != i and sales[i][j] + v > sales[king[j]][j]){
            if(++cnt[i] == k){
                answer++;
            }
            if(cnt[king[j]]-- == k){
                answer--;
            }
            king[j] = i;
        }

        sales[i][j] += v;
        cout << answer << "\n";

    }    

    return 0;
}