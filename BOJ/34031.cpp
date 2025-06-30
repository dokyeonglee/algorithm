#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<int> count_prefix_balance(const string& str) {
    int balance = 0;
    vector<int> balance_count(str.size() + 1);

    for (const char c : str) {
        balance += (c == '(' ? 1 : -1);
        if (balance < 0) {
            break;
        }
        ++balance_count[balance];
    }

    return balance_count;
}

ll count_valid_combinations(const string& a, const string& b) {
    const vector<int> balance_count = count_prefix_balance(a);

    int balance = 0, min_balance = 0;
    ll valid_combinations = 0;

    for (const char c : b) {
        balance += (c == '(' ? 1 : -1);
        min_balance = min(min_balance, balance);

        if (balance == min_balance && balance <= 0 && -balance < balance_count.size()) {
            valid_combinations += balance_count[-balance];
        }
    }

    return valid_combinations;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    
    cout << count_valid_combinations(a, b) << '\n';

    return 0;
}