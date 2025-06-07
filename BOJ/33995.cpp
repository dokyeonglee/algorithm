#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool can_make_lcs_length_k(const string& str, const int k) {
    vector<int> frequency(26);
    for (auto& c : str) {
        ++frequency[c - 'a'];
    }
    return *min_element(frequency.begin(), frequency.end()) <= k;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const string answer_string = "01";

    int n, k;
    cin >> n >> k;

    string str;
    cin >> str;

    if (can_make_lcs_length_k(str, k)) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }

    return 0;
}