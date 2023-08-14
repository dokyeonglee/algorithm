#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> arr(n + 1, vector<int>(20));

    for(int i = 1; i <= n; i++){
        cin >> arr[i][0];
    }

    for(int i = 1; i < 20; i++){
        for(int j = 1; j <= n; j++){
            arr[j][i] = arr[arr[j][i - 1]][i - 1];
        }
    }

    int q;
    cin >> q;

    while(q--){
        int n, x;
        cin >> n >> x;
        for(int i = 0; n >= (1 << i); i++){
            if(n & (1 << i)){
                x = arr[x][i];
            }
        }
        cout << x << "\n";
    }

    return 0;
}