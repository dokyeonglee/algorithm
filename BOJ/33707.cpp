#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int x;

    for(int i = 1; i <= n; i++){
        for(int j = (i & 1) + 1; j <= m; j += 2){
            cout << "? " << i << " " << j << endl;
            cin >> x;
            if(x == 1){
                return 0;
            }
        }
    }

    return 0;

}