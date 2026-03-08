#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int& a : arr) {
            cin >> a;
        }

        bool possible = true;

        stack<int> s;
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 1) {
                s.push(arr[i]);
            } else {
                while (!s.empty() && s.top() + 1 != arr[i]) { 
                    int sz = min((int)s.size(), s.top());
                    while (sz--) {
                        s.pop();
                    }
                }
                if (!s.empty() && s.top() + 1 == arr[i]) { 
                    s.push(arr[i]);
                } else {
                    possible = false;
                    break;
                }
            }
        }

        if (possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}