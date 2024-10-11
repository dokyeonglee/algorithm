#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    set<int> unused;

    for(int i = 1; i <= n; i++){
        unused.insert(i);
    }

    vector<int> arr(n + 1);    

    for(int i = 1; i <= q; i++){
        int t, x;
        cin >> t >> x;
        if(t == 1){
            auto it = unused.lower_bound(x);
            if(it != unused.end()){
                unused.erase(it);
                arr[*it] = i;
                cout << *it << "\n";
            }else{
                cout << "-1\n";
            }
        }else{
            if(arr[x]){
                cout << arr[x] << "\n";
                arr[x] = 0;
                unused.insert(x);
            }else{
                cout << "-1\n";
            }
        }
    }    

    return 0;
}