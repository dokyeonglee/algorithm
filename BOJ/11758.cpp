#include <iostream>
#include <vector>

using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3 , int y3){
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int answer = ccw(x1, y1, x2, y2, x3, y3);

    if(answer != 0){
        answer /= abs(answer);
    }

    cout << answer;

    return 0;
}