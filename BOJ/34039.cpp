#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr int MAX_TIME = 100000;

struct Query {
    int type;
    int x;
    int y = -1;
};

ll prefix_sum(const vector<ll>& fenwick_tree, int idx) {
    ll result = 0;
    while (idx > 0) {
        result += fenwick_tree[idx];
        idx -= (idx & -idx);
    }
    return result;
}

void update(vector<ll>& fenwick_tree, int idx, const int value) {
    while (idx < fenwick_tree.size()) {
        fenwick_tree[idx] += value;
        idx += (idx & -idx);
    }
}

int calculate_max_clearable(const vector<ll>& time_tree, const vector<ll>& count_tree, const int t, const int n) {
    int left = 1;
    int right = MAX_TIME;
    int key = -1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (prefix_sum(time_tree, mid) < t) {
            left = mid + 1;
        } else {
            key = mid;
            right = mid - 1;
        }
    }

    if (key == -1) {
        return n;
    }

    ll excess_time = prefix_sum(time_tree, key) - t;
    ll reduce_count = (excess_time + key - 1) / key;
    int clearable_song_count = prefix_sum(count_tree, key) - reduce_count;

    return clearable_song_count;
}

void add_song(vector<ll>& time_tree, vector<ll>& count_tree, int song_time) {
    update(time_tree, song_time, song_time);
    update(count_tree, song_time, 1);
}

void remove_song(vector<ll>& time_tree, vector<ll>& count_tree, int song_time) {
    update(time_tree, song_time, -song_time);
    update(count_tree, song_time, -1);
}

vector<int> process_queries(vector<int>& song_times, const vector<Query>& queries) {
    vector<ll> time_tree(MAX_TIME + 1);
    vector<ll> count_tree(MAX_TIME + 1);

    for (int i = 1; i < song_times.size(); ++i) {
        add_song(time_tree, count_tree, song_times[i]);
    }

    vector<int> results;
    for (auto& q : queries) {
        if (q.type == 1) {
            remove_song(time_tree, count_tree, song_times[q.x]);
            song_times[q.x] = q.y;
            add_song(time_tree, count_tree, song_times[q.x]);
        } else if (q.type == 2) {
            int song_count = calculate_max_clearable(time_tree, count_tree, q.x, song_times.size() - 1);
            results.push_back(song_count);
        } else {
            add_song(time_tree, count_tree, q.x);
            song_times.emplace_back(q.x);
        }
    }

    return results;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> song_times(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> song_times[i];
    }

    vector<Query> queries(q);
    for (auto& q : queries) {
        cin >> q.type >> q.x;
        if (q.type == 1) {
            cin >> q.y;
        }
    }

    auto results = process_queries(song_times, queries);
    for (auto& song_count : results) {
        cout << song_count << '\n';
    }

    return 0;
}