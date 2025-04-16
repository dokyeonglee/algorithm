#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    bool check = false;

    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(x == i){
            check = true;
            break;
        }
    }

    if(check){
        cout << -1;
    }else{
        cout << 1000000007;
    }

    return 0;

}