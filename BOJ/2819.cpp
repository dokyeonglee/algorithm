#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    long long answer = 0;

    vector<int> x_pos(n);
    vector<int> y_pos(n);

    for(int i = 0; i < n; i++){
        cin >> x_pos[i] >> y_pos[i];
        answer += abs(x_pos[i]) + abs(y_pos[i]);
    }

    sort(x_pos.begin(), x_pos.end());
    sort(y_pos.begin(), y_pos.end());

    string str;
    cin >> str;

    int x = 0;
    int y = 0;

    for(auto& c : str){
        int diff = 0;
        if(c == 'S'){
            diff = upper_bound(y_pos.begin(), y_pos.end(), y++) - y_pos.begin();
            diff = 2 * diff - n;
        }else if(c == 'J'){
            diff = lower_bound(y_pos.begin(), y_pos.end(), y--) - y_pos.begin();
            diff = -2 * diff + n;
        }else if(c == 'I'){
            diff = upper_bound(x_pos.begin(), x_pos.end(), x++) - x_pos.begin();
            diff = 2 * diff - n;
        }else{
            diff = lower_bound(x_pos.begin(), x_pos.end(), x--) - x_pos.begin();
            diff = -2 * diff + n;
        }
        answer += diff;
        cout << answer << "\n";
    }

    return 0;

}