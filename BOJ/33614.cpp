#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int p, q, r;
        cin >> p >> q >> r;
        cout << min(q, r) + p - 1 << "\n";
    }

    return 0;

}