#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int col = 1;

    while(--n){
        int x;
        cin >> x;
        if(x == 1){
            char d;
            int c;
            cin >> c >> d;
            if(d == 'L'){
                col = max(col, c + 1);
            }else{
                if(col >= c){
                    col = m + 1;
                }
            }
        }else if(x == 2){
            char d1, d2;
            int c1, c2;
            cin >> c1 >> d1 >> c2 >> d2;
            if(d1 == 'L'){
                if(d2 == 'L'){
                    col = max(col, c2 + 1);
                }else{
                    col = max(col, c1 + 1);
                    if(col >= c2){
                        col = m + 1;
                    }
                }
            }else{
                if(d2 == 'L'){
                    if(col >= c1){
                        col = max(col, c2 + 1);
                    }
                }else{
                    if(col >= c1){
                        col = m + 1;
                    }
                }
            }
        }
        if(col > m){
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;

}