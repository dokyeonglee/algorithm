#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<int, vector<int>> mp;
    map<int, vector<int>> mp2;

    int n, m;
    cin >> n >> m;

    int x = 0;
    int y = 0;

    while(n--){
        cin >> x >> y;
        mp[x].push_back(y);
        mp2[y].push_back(x);
    }

    for(auto& it : mp){
        sort(it.second.begin(), it.second.end());
    }

    for(auto& it : mp2){
        sort(it.second.begin(), it.second.end());
    }

    string command;
    cin >> command;

    x = 0;
    y = 0;

    for(auto& c : command){
        if(c == 'U'){
            y = *upper_bound(mp[x].begin(), mp[x].end(), y);
        }else if(c == 'D'){
            y = *(lower_bound(mp[x].begin(), mp[x].end(), y) - 1);
        }else if(c == 'R'){
            x = *upper_bound(mp2[y].begin(), mp2[y].end(), x);
        }else if(c == 'L'){
            x = *(lower_bound(mp2[y].begin(), mp2[y].end(), x) - 1);
        }
    }

    cout << x << " " << y;

    return 0;
}