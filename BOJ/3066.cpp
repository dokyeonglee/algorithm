#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> v;
        v.push_back(-1);
        while(n--){
            int x;
            cin >> x;
            if(v.back() < x){
                v.push_back(x);
            }else{
                auto it = lower_bound(v.begin(), v.end(), x);
                *it = x;
            }
        }
        cout << v.size() - 1 << "\n";
    }

    return 0;
}