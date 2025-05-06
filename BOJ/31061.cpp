#include <iostream>
#include <vector>
#include <bitset>
#include <cassert>

using namespace std;

constexpr int MAX_BARNS = 500001;

int max_same_label_barns_in_cycle(const vector<int>& cycle_a, const vector<int>& cycle_b, const vector<int>& cycle_a_indices, const int cycle_b_dir){
    
    int result = 0;
    int k = cycle_a.size();
    int cycle_b_idx = (cycle_b_dir == 1 ? 0 : k - 1);

    vector<int> same_label_count(k);

    for(int i = 0; i < k; i++){
        if(cycle_a_indices[cycle_b[i]] != -1){
            int diff = (cycle_b_idx - cycle_a_indices[cycle_b[i]] + k) % k;
            result = max(result, ++same_label_count[diff]);
        }
        cycle_b_idx += cycle_b_dir;
    }

    return result;

}

int number_of_barns_not_in_cycle(const vector<int>& cycle_a, const vector<int>& cycle_b, int n){

    int result = n;
    bitset<MAX_BARNS> barns_in_cycle;

    for(int i = 0; i < cycle_a.size(); i++){
        barns_in_cycle[cycle_a[i]] = true;
        barns_in_cycle[cycle_b[i]] = true;
    }

    result -= barns_in_cycle.count();

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    assert(n >= 3 and n <= MAX_BARNS);
    assert(k >= 3 and k <= n);

    vector<int> cycle_a(k);
    vector<int> cycle_b(k);

    for(int i = 0; i < k; i++){
        cin >> cycle_a[i];
        assert(cycle_a[i] >= 1 and cycle_a[i] <= n);
    }

    for(int i = 0; i < k; i++){
        cin >> cycle_b[i];
        assert(cycle_b[i] >= 1 and cycle_b[i] <= n);
    }

    vector<int> cycle_a_indices(n + 1, -1);
    for(int i = 0; i < k; i++){
        cycle_a_indices[cycle_a[i]] = i;
    }

    int answer = number_of_barns_not_in_cycle(cycle_a, cycle_b, n);
    answer += max(max_same_label_barns_in_cycle(cycle_a, cycle_b, cycle_a_indices, 1), max_same_label_barns_in_cycle(cycle_a, cycle_b, cycle_a_indices, -1));

    cout << answer;

    return 0;

}