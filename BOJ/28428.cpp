#include <iostream>
#include <vector>

using namespace std;

int compare(int a, int b){
    return (a > b) - (a < b);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int sx, sy, mx, my;
    cin >> sx >> sy >> mx >> my;

    if(compare(sx, sy) == compare(mx, my)){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}