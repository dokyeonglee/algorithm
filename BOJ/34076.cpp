#include <iostream>

using namespace std;
using ll = long long;

constexpr int MIN_LENGTH = 11;
const string RAITHORSE = "raithorse";
const int RAITHORSE_LENGTH = RAITHORSE.size();

int calculate_best_b_count(const int n) {
    int max_subsequence_count = 0;
    int b_count = 0;

    for (int b = 2; b <= n - RAITHORSE_LENGTH; ++b) {
        ll subsequence_count = b * (b - 1) / 2;
        const int base = (n - b) / RAITHORSE_LENGTH;
        const int extra = (n - b) % RAITHORSE_LENGTH;

        for (int i = 0; i < extra; ++i) {
            subsequence_count *= base + 1;
        }
        for (int i = extra; i < RAITHORSE_LENGTH; ++i) {
            subsequence_count *= base;
        }

        if (max_subsequence_count < subsequence_count) {
            max_subsequence_count = subsequence_count;
            b_count = b;
        }
    }

    return b_count;
}

string generate_explanation(const int n) {
    if (n < MIN_LENGTH) {
        return string(n, 'r');
    }

    const int b_count = calculate_best_b_count(n);
    const int base = (n - b_count) / RAITHORSE_LENGTH;
    const int extra = (n - b_count) % RAITHORSE_LENGTH;

    string explanation;

    for (int i = 0; i < 2; ++i) {
        int count = base;
        if (i < extra) {
            ++count;
        }
        explanation.append(count, RAITHORSE[i]);
    }

    explanation.append(b_count, 'b');

    for (int i = 2; i < RAITHORSE_LENGTH; ++i) {
        int count = base;
        if (i < extra) {
            ++count;
        }
        explanation.append(count, RAITHORSE[i]);
    }

    return explanation;
}

int main(){
    int n;
    cin >> n;

    cout << generate_explanation(n);

    return 0;
}