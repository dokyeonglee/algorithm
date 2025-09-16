#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

constexpr int BULLSEYE_SCORE = 50;
constexpr int BULL_SCORE = 25;
constexpr double MEAN_SCORE = 10.5;

double probability(const double inner, const double outer, const double variance) {
    return exp(-(inner * inner) / (2 * variance)) - exp(-(outer * outer) / (2 * variance));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    double bullseye, bull, triple_inner, triple_outer, double_inner, double_outer;
    cin >> bullseye >> bull >> triple_inner >> triple_outer >> double_inner >> double_outer;

    double sigma;
    cin >> sigma;

    double variance = sigma * sigma;

    double expected_score = 0.0;
    expected_score += probability(0, bullseye, variance) * BULLSEYE_SCORE;
    expected_score += probability(bullseye, bull, variance) * BULL_SCORE;
    expected_score += probability(bull, double_outer, variance) * MEAN_SCORE;
    expected_score += probability(double_inner, double_outer, variance) * MEAN_SCORE;
    expected_score += probability(triple_inner, triple_outer, variance) * MEAN_SCORE * 2;

    cout << fixed;
    cout.precision(10);
    cout << expected_score << '\n';

    return 0;
}