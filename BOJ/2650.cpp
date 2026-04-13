#include <iostream>
#include <vector>

using namespace std;
using Point = pair<int, int>;

struct Line {
    Point a;
    Point b; 
};

Point read_point() {
    Point point;
    cin >> point.first >> point.second;

    if (point.first == 1) {
        point.first = point.second;
        point.second = 0;
    } else if (point.first == 2) {
        point.first = point.second;
        point.second = 51;
    } else if (point.first == 3) {
        point.first = 0;
    } else {
        point.first = 51;
    }

    return point;
}

int ccw(const Point& a, const Point& b, const Point& c) {
    int result = (a.second - b.second) * (b.first - c.first)
            - (a.first - b.first) * (b.second - c.second);

    if (result > 0) {
        return 1;
    } else if (result < 0) {
        return -1;
    }
    return 0;
}

bool is_intersect(const Line& line1, const Line& line2) {
    const auto& [p1, p2] = line1;
    const auto& [p3, p4] = line2;

    int ccw1 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int ccw2 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if (ccw1 == 0 && ccw2 == 0) {
        if (p1 < p3) {
            return p3 < p2 && p2 < p4;
        } else {
            return p1 < p4 && p4 < p2;
        }
    }

    return ccw1 <= 0 && ccw2 <= 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Line> lines(n / 2);
    for (auto& [a, b] : lines) {
        a = read_point();
        b = read_point();
        if (a > b) {
            swap(a, b);
        }
    }

    int total_intersections = 0;
    int max_intersection = 0;

    for (int i = 0 ; i < lines.size(); ++i) {
        int intersections = 0;
        for (int j = 0; j < lines.size(); ++j) {
            if (i == j) {
                continue;
            }
            intersections += is_intersect(lines[i], lines[j]);
        }
        max_intersection = max(max_intersection, intersections);
        total_intersections += intersections;
    }

    total_intersections /= 2;

    cout << total_intersections << '\n';
    cout << max_intersection << '\n';

    return 0;
}