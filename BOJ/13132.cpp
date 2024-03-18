#include <iostream>
#include <vector>

using namespace std;

double solve(vector<int>& p, vector<double>& r, int m, double limit, int idx, double money){

    if(money <= limit){
        return 0;
    }

    if(idx == p.size()){
        return (money > 1e12) * 100.0;
    }

    double betting = money / 100 * m;
    money -= betting;

    double result = p[idx] / 100.0 * solve(p, r, m, limit, idx + 1, money + betting * r[idx])
                + (1 - p[idx] / 100.0) * solve(p, r, m, limit, idx + 1, money);

    
    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, b;
    cin >> n >> m >> b;

    vector<int> p(n);
    vector<double> r(n);

    for(int i = 0; i < n; i++){
        cin >> p[i] >> r[i];
    }

    cout << fixed;
    cout.precision(9);
    cout << solve(p, r, m, 1e12 / 100 * b, 0, 1e12);

    return 0;
}