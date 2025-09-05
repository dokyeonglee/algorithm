#include <iostream>
#include <vector>

using namespace std;

pair<int, int> median_range(const int physic_score, const int information_score, const int math_score) {
    const int left = min(physic_score, min(information_score, math_score));
    const int right = max(physic_score, max(information_score, math_score));
    return {left, right};
}

bool can_make_portfolio(const vector<int>& physic, const vector<int>& information, const vector<int>& math) {
    int prev_median = -1;

    for (int i = 0; i < physic.size(); ++i) {
        auto [left, right] = median_range(physic[i], information[i], math[i]);

        if (prev_median >= right) {
            return false;
        }

        prev_median = max(prev_median + 1, left);
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<int> physic(n);
    vector<int> information(n);
    vector<int> math(n);

    for (int& score : physic) {
        cin >> score;
    }

    for (int& score : information) {
        cin >> score;
    }
    
    for (int& score : math) {
        cin >> score;
    }

    if (can_make_portfolio(physic, information, math)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}