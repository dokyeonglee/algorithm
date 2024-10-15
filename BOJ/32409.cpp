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

        bool check = true;

        int x = 0;
        int y = 0;

        for(int i = 1; i < n; i++){
            cin >> y;
            if(y <= x){
                check = false;
            }else{
                y -= x + 1;
            }
            x = y;
        }

        cin >> y;

        if(!(y == x or y - x == 1)){
            check = false;
        }

        if(check){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }

    }

    return 0;
}