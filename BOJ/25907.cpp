#include <iostream>

using namespace std;

constexpr int MAX_ASK_QUERIES = 19;

int ask_query(const int day) {
    cout << "? " << day << endl;

    int sheep_count;
    cin >> sheep_count;

    return sheep_count;
}

void answer_query(const int day) {
    cout << "! " << day << endl;
}

int compare_sheep_vs_wolf(const int day) {
    const int sheep_count = ask_query(day);
    const int wolf_count = day - sheep_count;

    return (sheep_count > wolf_count) - (sheep_count < wolf_count);
}

int find_working_day(const int n) {
    int left = 1;
    int right = n;

    for (int i = 0; i < MAX_ASK_QUERIES; ++i) {
        int mid = (left + right) / 2;
        int cmp = compare_sheep_vs_wolf(mid);

        if (cmp == 0) {
            return mid;
        }

        if (cmp == 1) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return 0;
}

int main(){
    int n;
    cin >> n;

    const int working_day = find_working_day(n);
    answer_query(working_day);

    return 0;
}