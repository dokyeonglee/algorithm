#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        if(x1 == 0 and y1 == 0 and x2 == 0 and y2 == 0 and x3 == 0 and y3 == 0){
            break;
        }
        int _2s = abs((x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3));
        int b = gcd(abs(x1 - x2), abs(y1 - y2)) + gcd(abs(x1 - x3), abs(y1 - y3)) + gcd(abs(x2 - x3), abs(y2 - y3)) - 1;
        cout << (_2s - b + 2) / 2 << "\n";
    }

    return 0;
}