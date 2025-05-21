#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculate_max_pairs(const vector<int>& weights, const int weight_limit, int left, int right, int exclude_index = -1) {

    int max_pairs = 0;

    while (left < right) {
        if (left == exclude_index) {
            ++left;
        } else if (right == exclude_index) {
            --right;
        } else {
            if (weights[left] + weights[right] <= weight_limit) {
                ++max_pairs;
                ++left;
            }
            --right;
        }
    }

    return max_pairs;
}

int calculate_max_pairs(const vector<int>& weights, const int weight_limit, int exclude_index = -1) {
    int left = 0;
    int right = weights.size() - 1;
    return calculate_max_pairs(weights, weight_limit, left, right, exclude_index);
}

int find_min_excludable_index(const vector<int>& weights, const int original_pairs, const int weight_limit) {

    if (original_pairs * 2 >= weights.size()) {
        return - 1;
    }

    int left = 0;
    int right = original_pairs * 2;
    int min_excludable_index = right;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (calculate_max_pairs(weights, weight_limit, mid) == original_pairs) {
            min_excludable_index = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return min_excludable_index;
}

bool has_mixed_pen(const vector<int>& group1_weights, const int group1_max_pairs, const vector<int>& group2_weights, const int group2_max_pairs, const int weight_limit) {

    int group1_excludable_index = find_min_excludable_index(group1_weights, group1_max_pairs, weight_limit);
    int group2_excludable_index = find_min_excludable_index(group2_weights, group2_max_pairs, weight_limit);

    if (group1_excludable_index == -1 || group2_excludable_index == -1) {
        return false;
    }

    return group1_weights[group1_excludable_index] + group2_weights[group2_excludable_index] <= weight_limit;
}

int compute_min_pens(vector<int>& group1_weights, vector<int>& group2_weights, const int weight_limit) {

    sort(group1_weights.begin(), group1_weights.end());
    sort(group2_weights.begin(), group2_weights.end());

    int min_pens = group1_weights.size() + group2_weights.size();
    const int group1_max_pairs = calculate_max_pairs(group1_weights, weight_limit);
    const int group2_max_pairs = calculate_max_pairs(group2_weights, weight_limit);

    min_pens -= group1_max_pairs + group2_max_pairs;
    min_pens -= has_mixed_pen(group1_weights, group1_max_pairs, group2_weights, group2_max_pairs, weight_limit);

    return min_pens;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int number_of_sheep, number_of_wolves, weight_limit;
    cin >> number_of_sheep >> number_of_wolves >> weight_limit;

    vector<int> sheep_weights(number_of_sheep);
    vector<int> wolf_weights(number_of_wolves);

    for (auto& weight : sheep_weights) {
        cin >> weight;
    }

    for (auto& weight : wolf_weights) {
        cin >> weight;
    }

    int min_pens = compute_min_pens(sheep_weights, wolf_weights, weight_limit);
    cout << min_pens;

    return 0;
}