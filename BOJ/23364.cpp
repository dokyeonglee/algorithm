#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, int> mp;

    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(mp.count(x)){
            cout << mp[x] << " " << i;
            return 0;
        }
        mp[x] = i;
    }

    return 0;
}