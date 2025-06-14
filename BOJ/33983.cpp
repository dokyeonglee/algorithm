#include <iostream>

using namespace std;

bool is_pure_water(const string& str) {

    if (str.size() % 3 != 0) {
        return false;
    }
    if (str.front() == 'O' || str.back() == 'O') {
        return false;
    }

    int total_molecules = str.size() / 3;
    int h_balance = 0;

    for (int i = 0; i < str.size(); ++i) {

        if (str[i] == 'H') {
            ++h_balance;
        } else {
            --h_balance;
        }

        if (h_balance < 0 || h_balance > total_molecules) {
            return false;
        }
    }

    return h_balance == str.size() / 3;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string str;
    cin >> str;

    if (is_pure_water(str)) {
        cout << "pure\n";
    } else {
        cout << "mix\n";
    }

    return 0;
}