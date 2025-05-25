#include <iostream>
#include <vector>

using namespace std;

vector<int> find_spiral_path(const int x, const int y) {
    if (x < y) {
        return {x, y};
    } else if (y >= 4) {
        return {1, 2, 3, x - y + 5, x + 2, x + 3};
    }
    return {};
}

void print_result(const int test_case_number, const vector<int>& path) {
    cout << test_case_number << ' ';
    if (path.empty()) {
        cout << "NO PATH";
    } else {
        cout << path.size() << ' ';
        for (auto& x : path) {
            cout << x << ' ';
        }
    }
    cout << '\n';
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int test_case_number, x, y;
        cin >> test_case_number >> x >> y;
        vector<int> path = find_spiral_path(x, y);
        print_result(test_case_number, path);
    }

    return 0;

}