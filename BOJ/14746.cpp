#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    int c1, c2;
    cin >> c1 >> c2;

    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }

    vector<int> q(m);
    for(int i = 0; i < m; i++){
        cin >> q[i];
    }

    sort(p.begin(), p.end());
    sort(q.begin(), q.end());

    int min_x_diff = 1e9;
    int cnt = 0;

    int idx = 0;
    int idx2 = 0;

    while(idx < n){
        while(idx2 < m and p[idx] > q[idx2]){
            if(min_x_diff > abs(p[idx] - q[idx2])){
                min_x_diff = abs(p[idx] - q[idx2]);
                cnt = 1;
            }else if(min_x_diff == abs(p[idx] - q[idx2])){
                cnt++;
            }
            idx2++;
        }
        if(idx2 < m){
            if(min_x_diff > abs(p[idx] - q[idx2])){
                min_x_diff = abs(p[idx] - q[idx2]);
                cnt = 1;
            }else if(min_x_diff == abs(p[idx] - q[idx2])){
                cnt++;
            }
        }
        idx++;
    }

    cout << min_x_diff + abs(c1 - c2) << " " << cnt;


    return 0;

}