#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int x, y;
        cin >> x >> y;
        if(x == y){
            cout << "0\n";
            continue;
        }
        int temp = y - x;
        int s = sqrt(temp);
        int answer = 2 * s - 1 + (temp - s * s > 0) + (temp - s * s - s > 0);
        cout << answer << "\n";
    }

    return 0;
}