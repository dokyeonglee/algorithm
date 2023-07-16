#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    set<pair<int, int>> s;
    vector<int> v(1e6 + 1, -1);
    vector<int> v2(1e6 + 1, 987654321);
    
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        s.insert(make_pair(l, r));
        v[l] = max(v[l], r);
        v2[r] = min(v2[r], l);
    }

    int q;
    cin >> q;

    while(q--){
        int l, r;
        cin >> l >> r;
        int answer = -1;
        if(s.count(make_pair(l, r))){
            answer = 1;
        }else if(v[l] >= r and v2[r] <= l){
            answer = 2;
        }
        cout << answer << "\n";
    }

    return 0;
}