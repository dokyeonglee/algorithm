#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<unsigned int>> bit(n + 1, vector<unsigned int>(64));

    for(int i = 1; i <= n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < n; j++){
            bit[i][j / 32] |= (str[j] - '0') << (j % 32);
        }
    }

    int q;
    cin >> q;

    while(q--){
        int a, b;
        cin >> a >> b;
        int answer = 0;
        for(int i = 0; i < 64; i++){
            answer += __builtin_popcount(bit[a][i] & bit[b][i]);
        }
        cout << answer << "\n";
    }

    return 0;
}