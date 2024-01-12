#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<long long, long long>> arr(n);
    for(auto& x : arr){
        cin >> x.first >> x.second;
    }

    int m;
    cin >> m;

    vector<long long> y_indices(m);
    vector<long long> y_value(m);
    
    for(int i = 0; i < m; i++){
        cin >> y_indices[i] >> y_value[i];
    }

    for(int i = 1; i < m; i++){
        y_value[i] += y_value[i - 1];
    }

    int a, b;
    cin >> a >> b;

    long long answer = 0;

    for(auto& x : arr){
        int s = lower_bound(y_indices.begin(), y_indices.end(), x.first + a) - y_indices.begin();
        int e = upper_bound(y_indices.begin(), y_indices.end(), x.first + b) - y_indices.begin();
        if(e){
            e--;
        }else{
            continue;
        }
        if(s){
            answer += x.second * (y_value[e] - y_value[s - 1]);
        }else{
            answer += x.second * y_value[e];
        }
    }

    cout << answer;

    return 0;
}