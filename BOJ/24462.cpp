#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

using ll = long long;

struct AlarmPair {
    pair<int, int> indices;
    int ring_count = 0;
};

class Alarm {
public:
    const ll start;
    const ll snooze;
    const int ring_count;

    Alarm(int wake_up_time, ll start, ll snooze)
        : start(start), snooze(snooze),
        ring_count(count_ring_up_to(wake_up_time)) {}

    static int count_ring_up_to(const int wake_up_time, const ll start, const ll snooze) {
        return wake_up_time / snooze - start / snooze + 1;
    }

private:
    int count_ring_up_to(const int wake_up_time) const {
        return wake_up_time / snooze - start / snooze + 1;
    }
};

ll count_overlap_rings(const int wake_up_time, const vector<Alarm>& alarms, const int i, const int j) {
    ll snooze_lcm = lcm(alarms[i].snooze, alarms[j].snooze);
    ll adjusted_overlap_start = max(alarms[i].start, alarms[j].start) + snooze_lcm - 1;
    return Alarm::count_ring_up_to(wake_up_time, adjusted_overlap_start, snooze_lcm);
}

AlarmPair find_best_alarm_pair(const int wake_up_time, const vector<Alarm>& alarms) {
    
    const int n = alarms.size();

    AlarmPair best_alarm_pair;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int overlap_ring_count = count_overlap_rings(wake_up_time, alarms, i, j);
            int alarm_pair_ring_count = alarms[i].ring_count + alarms[j].ring_count - overlap_ring_count;
            if (best_alarm_pair.ring_count < alarm_pair_ring_count) {
                best_alarm_pair.ring_count = alarm_pair_ring_count;
                best_alarm_pair.indices = {i + 1, j + 1};
            }
        }
    }

    return best_alarm_pair;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, wake_up_time;
    cin >> n >> wake_up_time;

    vector<Alarm> alarms; alarms.reserve(n);
    for (int i = 0; i < n; ++i) {
        int start, snooze;
        cin >> start >> snooze;
        alarms.emplace_back(wake_up_time, start, snooze);
    }

    AlarmPair best_alarm_pair = find_best_alarm_pair(wake_up_time, alarms);

    cout << best_alarm_pair.indices.first << ' ' << best_alarm_pair.indices.second << '\n';
    cout << best_alarm_pair.ring_count << '\n';

    return 0;
}