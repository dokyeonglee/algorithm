#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int base36_char_to_int(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'Z') {
        return 10 + (c - 'A');
    }
    return -1;
}

int calculate_remainder(const string& base36_str, int p) {
    int remainder = 0;
    for (int i = 0; i < base36_str.size(); i++) {
        remainder = (remainder * 36 + base36_char_to_int(base36_str[i])) % p;
    }
    return remainder;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string base36_str;
    cin >> base36_str;

    int k, p;
    cin >> k >> p;

    int min_edit_count = INT_MAX;
    const int remainder = calculate_remainder(base36_str, p);

    if (remainder == k) {
        min_edit_count = 0;
    } else if (base36_str.size() == 1) {
        if (k < 36) {
            min_edit_count = 1;
        }
    } else {
        min_edit_count = 2;

        int power_of_36_mod_p = 1;

        for (int i = base36_str.size() - 1; i >= 0; i--) {
            int original_digit = base36_char_to_int(base36_str[i]);

            for (int j = 0; j < 36; j++) {
                int diff = ((j - original_digit) * power_of_36_mod_p % p + p) % p;

                if ((remainder + diff) % p == k) {
                    min_edit_count = 1;
                    break;
                }
            }

            if (min_edit_count == 1) {
                break;
            }

            power_of_36_mod_p = power_of_36_mod_p * 36 % p;
        }
    }

    if (min_edit_count == INT_MAX) {
        min_edit_count = -1;
    }

    cout << min_edit_count;

    return 0;

}