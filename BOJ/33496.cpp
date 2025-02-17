#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> x_intercpets_slope_1(n);
    vector<int> x_intercpets_slope_minus_1(n);

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        x_intercpets_slope_1[i] = x - y;
        x_intercpets_slope_minus_1[i] = x + y;
    }

    sort(x_intercpets_slope_1.begin(), x_intercpets_slope_1.end());
    sort(x_intercpets_slope_minus_1.begin(), x_intercpets_slope_minus_1.end());

    x_intercpets_slope_1.erase(unique(x_intercpets_slope_1.begin(), x_intercpets_slope_1.end()), x_intercpets_slope_1.end());
    x_intercpets_slope_minus_1.erase(unique(x_intercpets_slope_minus_1.begin(), x_intercpets_slope_minus_1.end()), x_intercpets_slope_minus_1.end());

    long long answer = x_intercpets_slope_1.size() + x_intercpets_slope_minus_1.size();

    for(int x : x_intercpets_slope_1){
        auto it = lower_bound(x_intercpets_slope_minus_1.begin(), x_intercpets_slope_minus_1.end(), x);
        answer += x_intercpets_slope_minus_1.end() - it;
        if(*it == x){
            answer -= 2;
        }
    }

    cout << answer;

    return 0;

}