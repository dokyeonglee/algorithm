#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    int duration;
    int deadline;
};

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Task> tasks(n);
    for (auto& task : tasks) {
        cin >> task.duration >> task.deadline;
    }

    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.deadline > b.deadline;
    });

    int latest_start_time = tasks[0].deadline - tasks[0].duration;

    for (int i = 1; i < n; i++) {
        if (tasks[i].deadline < latest_start_time) {
            latest_start_time = tasks[i].deadline - tasks[i].duration;
        } else {
            latest_start_time -= tasks[i].duration;
        }
    }

    latest_start_time = max(-1, latest_start_time);

    cout << latest_start_time;
    return 0;

}