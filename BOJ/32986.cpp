#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, y, z;
    cin >> x >> y >> z;

    if(x == 3 and y == 3 and z == 3){
        cout << 0;
    }else{
        cout << (min(x, min(y, z)) - 1) / 2;
    }

    return 0;
}