#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;

struct Gate {
    int flow;
    int cost;
};

struct Query {
    int volume;
    int time_limit;
};

map<ll, ll> generate_flow_cost_map(const vector<Gate>& gates) {
    const int n = gates.size();
    map<ll, ll> flow_cost_map;

    for (int i = 0; i < (1 << n); ++i) {
        ll flow_sum = 0;
        ll cost_sum = 0;

        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                flow_sum += gates[j].flow;
                cost_sum += gates[j].cost;
            }
        }

        auto [it, inserted] = flow_cost_map.insert({flow_sum, cost_sum});
        if (!inserted) {
            flow_cost_map[flow_sum] = min(flow_cost_map[flow_sum], cost_sum);
        }
    }

    return flow_cost_map;
}

void propagate_min_cost(map<ll, ll>& flow_cost_map) {
    auto it = flow_cost_map.rbegin();
    ll min_cost = it->second;
    ++it;

    while (it != flow_cost_map.rend()) {
        min_cost = min(min_cost, it->second);
        it->second = min_cost;
        ++it;
    }
}

vector<ll> process_queries(const map<ll, ll>& flow_cost_map, const vector<Query>& queries) {
    const int m = queries.size();
    vector<ll> results(m);

    const ll max_flow = flow_cost_map.rbegin()->first;

    for (int i = 0; i < m; ++i) {
        ll required_flow = (queries[i].volume + queries[i].time_limit - 1) / queries[i].time_limit;

        if (required_flow <= max_flow) {
            results[i] = flow_cost_map.lower_bound(required_flow)->second;
        } else {
            results[i] = -1;
        }
    }

    return results;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Gate> gates(n);
    for (auto& gate : gates) {
        cin >> gate.flow >> gate.cost;
    }

    int m;
    cin >> m;

    vector<Query> queries(m);
    for (auto& q : queries) {
        cin >> q.volume >> q.time_limit;
    }

    map<ll, ll> flow_cost_map = generate_flow_cost_map(gates);
    propagate_min_cost(flow_cost_map);
    auto results = process_queries(flow_cost_map, queries);

    for (int i = 0; i < m; ++i) {
        if (results[i] != -1) {
            cout << "Case " << i + 1 << ": " << results[i] << '\n';
        } else {
            cout << "Case " << i + 1 << ": IMPOSSIBLE\n";
        }
    }

    return 0;
}