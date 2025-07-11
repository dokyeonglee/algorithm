#include <iostream>
#include <vector>

using namespace std;

const vector<pair<int, int>> dx_dy[6] = {
    {},
    {},
    {},
    {{-1, 1}, {1, 1}, {-1, 1}, {1, -2}, {-1, 1}, {1, 1}}, 
    {{-1, 1}, {1, 1}, {-1, 2}, {1, -1}, {-1, -1}, {1, -1}, {-1, 2}, {1, 1}},
    {{-1, 1}, {1, 2}, {-1, 2}, {1, -1}, {-1, -2}, {1, -1}, {-1, 2}, {1, -1}, {-1, 2}, {1, 1}},
};

void print_path_segment(int& x, int& y, int m) {
    for (const auto [dx, dy] : dx_dy[m]) {
        x += dx;
        y += dy;
        cout << x << ' ' << y << '\n';
    }
}

void print_knishop_path(int m) {
    int x = 2;
    int y = 0;

    if (m < 3) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    while (m > 5) {
        print_path_segment(x, y, 3);
        m -= 3;
    }
    print_path_segment(x, y, m);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;

    print_knishop_path(m);
    
    return 0;
}