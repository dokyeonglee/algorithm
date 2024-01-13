#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    if(r1 > r2){
        swap(r1, r2);
    }

    double distance_square = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    double distance = sqrt(distance_square);
    double answer = 0;

    if(distance_square >= (r1 + r2) * (r1 + r2)){
        answer = 0;
    }else if(distance_square <= (r1 - r2) * (r1 - r2)){
        answer = 3.14159265358979 * r1 * r1;
    }else{
        double theta = 2 * acos((r1 * r1 + distance_square - r2 * r2) / (2 * r1 * distance));
        double theta2 = 2 * acos((r2 * r2 + distance_square - r1 * r1) / (2 * r2 * distance));
        answer = (r1 * r1 * theta + r2 * r2 * theta2 - r1 * r1 * sin(theta) - r2 * r2 * sin(theta2)) / 2;
    }

    cout << fixed;
    cout.precision(3);

    cout << answer;

    return 0;
}