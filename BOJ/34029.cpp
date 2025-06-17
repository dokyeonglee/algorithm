#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int min_hits_to_accept(const double batting_average, const int plate_appearances) {
    
    double p = batting_average;
    double q = 1.0 - p;

    double probability = pow(q, plate_appearances);
    double cumulative_probability = probability;
    int min_hits = 0;

    while (cumulative_probability < 0.05) {
        min_hits++;
        probability = probability * (plate_appearances + 1 - min_hits) / min_hits * p / q;
        cumulative_probability += probability;
    }

    return min_hits;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double batting_average;
    int plate_appearances;

    cin >> batting_average >> plate_appearances;

    cout << min_hits_to_accept(batting_average, plate_appearances);

    return 0;
}