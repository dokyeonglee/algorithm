#include <iostream>
#include <queue>

using namespace std;

constexpr int MIN_PAY = -10000;
constexpr int OFFSET = -MIN_PAY;
constexpr int MAX_PAY = 10000;
constexpr int PAY_LIMIT = MAX_PAY + OFFSET;

int count_min_coins(const vector<int>& coins, const int pay) {
    const int adjusted_pay = pay + OFFSET;

    vector<bool> visited(PAY_LIMIT + 1);
    visited[OFFSET] = true;

    queue<pair<int, int>> q;
    q.emplace(OFFSET, 0);
    
    while (!q.empty()) {
        auto [current_money, coin_count] = q.front();
        q.pop();

        if (current_money == adjusted_pay) {
            return coin_count;
        }

        for (const int coin : coins) {
            const int next_money = current_money + coin;

            if (next_money < 0 || next_money > PAY_LIMIT) {
                continue;
            }

            if (visited[next_money]) {
                continue;
            }

            visited[next_money] = true;
            q.emplace(next_money, coin_count + 1);
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, pay;
    cin >> n >> pay;

    vector<int> coins(n);
    for (auto& coin : coins) {
        cin >> coin;
    }

    cout << count_min_coins(coins, pay);

    return 0;
}