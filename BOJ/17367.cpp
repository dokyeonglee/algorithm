#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int get_earn(int a, int b, int c){
    if(a == b and b == c){
        return 10000 + 1000 * a;
    }else if(a == b or a == c){
        return 1000 + 100 * a;
    }else if(b == c){
        return 1000 + 100 * b;
    }else{
        return 100 * max(a, max(b, c));
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    double dp[n + 1][7][7][7] = {0};

    for(int x = 3; x <= n; x++){        
        for(int i = 1; i <= 6; i++){
            for(int j = 1; j <= 6; j++){
                double prev = 0;
                for(int k = 1; k <= 6; k++){
                    prev += dp[x - 1][k][i][j];
                }
                for(int k = 1; k <= 6; k++){
                    int earn = get_earn(i, j, k);
                    dp[x][i][j][k] = max((double)earn, prev / 6);
                }
            }
        }
    }

    double answer = 0;

    for(int i = 1; i <= 6; i++){
        for(int j = 1; j <= 6; j++){
            for(int k = 1; k <= 6; k++){
                answer += dp[n][i][j][k];
            }
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << answer / 216;

    return 0;
}