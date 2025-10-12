#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    stack<pair<int, int>> st;
    long long answer = 0;

    while (q--) {
        int type, x;
        cin >> type >> x;

        if (type == 1) {
            st.emplace(x, 1);
            answer += x;
        } else if (type = 2) {
            if (!st.empty()) {
                const int length = max(0, st.top().first - x);
                int cnt = 0;

                while (!st.empty() && st.top().first >= length) {
                    answer -= 1ll * (st.top().first - length) * st.top().second;
                    cnt += st.top().second;
                    st.pop();
                }

                if (cnt > 0) {
                    st.emplace(length, cnt);
                }
            }
        }
    }
    
    cout << answer << '\n';

    return 0;
}