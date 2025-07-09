#include <iostream>
#include <vector>

using namespace std;

vector<int> find_items_at_time(const vector<int>& health_conditions, int t) {
    vector<int> items;
    items.reserve(health_conditions.size());

    int max_health_so_far = health_conditions[0];
    int current_item = (t + max_health_so_far) / max_health_so_far;
    items.push_back(current_item);
    t -= health_conditions[0];

    for (int i = 1; i < health_conditions.size(); ++i) {
        max_health_so_far = max(max_health_so_far, health_conditions[i]);
        current_item = (t + max_health_so_far) / max_health_so_far;
        if ((current_item - 1) * max_health_so_far + health_conditions[i] <= t) {
            ++current_item;
        }

        current_item = min(current_item, items.back());
        if (current_item <= 1) {
            break;
        }

        items.push_back(current_item);
        t -= health_conditions[i];
    }

    items.resize(health_conditions.size(), 1);
    return items;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    vector<int> health_conditions(n);
    for (int& health : health_conditions) {
        cin >> health;
    }

    vector<int> items = find_items_at_time(health_conditions, t);
    for (const int current_item : items) {
        cout << current_item << '\n';
    }

    return 0;
}