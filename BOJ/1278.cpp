#include <iostream>
#include <vector>
#include <stack>

using namespace std;

enum class Action {
    CALL,
    ADD,
};

vector<int> generate_actor_order(const int actor_count) {
    stack<pair<int, Action>> st;
    st.emplace(actor_count, Action::CALL);

    vector<int> actor_order;

    while (!st.empty()) {
        int now = st.top().first;
        auto action = st.top().second;
        st.pop();

        if (now == 0) {
            continue;
        }

        if (action == Action::CALL) {
            st.emplace(now - 1, Action::CALL);
            st.emplace(now, Action::ADD);
            st.emplace(now - 1, Action::CALL);
        } else if (action == Action::ADD) {
            actor_order.push_back(now);
        }
    }

    actor_order.push_back(actor_count);

    return actor_order;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int actor_count;
    cin >> actor_count;

    vector<int> actor_order = generate_actor_order(actor_count);
    cout << actor_order.size() - 1 << '\n';
    for (int actor : actor_order) {
        cout << actor << '\n';
    }

    return 0;
}