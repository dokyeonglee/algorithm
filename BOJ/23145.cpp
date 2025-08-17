#include <iostream>
#include <queue>
#include <cstdint>

using namespace std;
using State = uint16_t;

constexpr int GRID_SIZE = 4;
constexpr int CELL_COUNT = GRID_SIZE * GRID_SIZE;

State swap_if_different(State state, const int i, const int j) {
    if ((state & (1u << i)) ==  (state & (1u << j))) {
        return state;
    }
    state ^= (1u << i);
    state ^= (1u << j);
    return state;
}

int calculate_min_swaps(const State initial_state, const State target_state) {
    vector<bool> visited(1 << CELL_COUNT);
    visited[initial_state] = true;

    queue<pair<State, int>> q;
    q.emplace(initial_state, 0);

    while (!q.empty()) {
        const auto [state, cnt] = q.front();
        q.pop();

        if (state == target_state) {
            return cnt;
        }

        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE - 1; ++j) {
                State next = swap_if_different(state, i * GRID_SIZE + j, i * GRID_SIZE + j + 1);
                if (!visited[next]) {
                    visited[next] = true;
                    q.emplace(next, cnt + 1);
                }
            }
        }

        for (int i = 0; i < GRID_SIZE - 1; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                State next = swap_if_different(state, i * GRID_SIZE + j, (i + 1) * GRID_SIZE + j);
                if (!visited[next]) {
                    visited[next] = true;
                    q.emplace(next, cnt + 1);
                }
            }
        }
    }
    
    return -1;
}

State read_state() {
    State state = 0;
    for (int i = 0; i < CELL_COUNT; ++i) {
        char c;
        cin >> c;

        if (c == 'L') {
            state |= (1u << i);    
        }
    }
    return state;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    State initial_state = read_state();
    State target_state = read_state();

    cout << calculate_min_swaps(initial_state, target_state) << '\n';

    return 0;
}