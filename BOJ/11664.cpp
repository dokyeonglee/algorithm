#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double distance(double x1, double y1, double z1, double x2, double y2, double z2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
}

double solve(){

    double x1, y1, z1, x2, y2, z2, x3, y3, z3;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3;

    double answer = 1e18;

    for(int i = 0; i < 100; i++){
        
        double x4 = (2 * x1 + x2) / 3.0;
        double y4 = (2 * y1 + y2) / 3.0;
        double z4 = (2 * z1 + z2) / 3.0;
        double cp = distance(x3, y3, z3, x4, y4, z4);

        double x5 = (x1 + 2 * x2) / 3.0;
        double y5 = (y1 + 2 * y2) / 3.0;
        double z5 = (z1 + 2 * z2) / 3.0;
        double cq = distance(x3, y3, z3, x5, y5, z5);

        if(cp < cq){
            x2 = x5;
            y2 = y5;
            z2 = z5;
        }else{
            x1 = x4;
            y1 = y4;
            z1 = z4;
        }
    }
    
    return distance(x3, y3, z3, x2, y2, z2);

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed;
    cout.precision(10);
    cout << solve();
    
    return 0;
}