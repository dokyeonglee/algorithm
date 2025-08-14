#include <iostream>
#include <cmath>

using namespace std;

/*
* |PA| >= |CA| - |PC|
* |PB| >= |CB| - |PC|
* => |PA| + 2 * |PB| + 3 * |PC| >= |CA| + 2 |CB|
*/

struct Point {
    double x;
    double y;
};

double calculate_distance(const Point& a, const Point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main(){
    Point a, b, c;

    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;

    double ca = calculate_distance(a, c);
    double cb = calculate_distance(b, c);

    cout << fixed;
    cout.precision(10);
    cout << ca + 2 * cb;

    return 0;
}