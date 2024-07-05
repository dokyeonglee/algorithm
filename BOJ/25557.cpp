#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<double>> dp(2405, vector<double>(2405, -1));

double solve(int k, int a, int b);

double f(int k, int a, int b, int p){
    if(k == p){
        return 1;
    }else if(k < p){
        return solve(k, a, p - 1) + 1;
    }else{
        return solve(k, p + 1, b) + 1;
    }
}

double solve(int k, int a, int b){

    if(k < a or k > b){
        return 0;
    }

    auto& ret = dp[k - a][b - a];
    if(ret != -1){
        return ret;
    }

    if(a == b){
        ret = 1;
    }else if((b - a) % 2 == 0){
        ret = (f(k, a, b, (a + b) / 2 - 1) + f(k, a, b, (a + b) / 2) + f(k, a, b, (a + b) / 2 + 1)) / 3;
    }else{
        ret = (f(k, a, b, (a + b - 1) / 2) + f(k, a, b, (a + b + 1) / 2)) / 2;
    }

    return ret;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cout << fixed;
    cout.precision(10);

    while(n--){
        int x, y, k;
        cin >> x >> y >> k;
        cout << solve(k, x, y) << '\n';
    }    

    return 0;
}