#include <iostream>
#include <vector>

using namespace std;

int roman_char_to_decimal(const char c) {
    if (c == 'I') {
        return 1;
    } else if (c == 'V') {
        return 5;
    } else if (c == 'X') {
        return 10;
    } else if (c == 'L') {
        return 50;
    }else if (c == 'C') {
        return 100;
    } else if (c == 'D') {
        return 500;
    }else if (c == 'M') {
        return 1000;
    }
    return -1;
}

string decimal_to_roman(int x) {
    static vector<pair<int, string>> table = {
        {1000, "M"}, {900, "CM"},
        {500, "D"},  {400, "CD"},
        {100, "C"},  {90, "XC"},
        {50, "L"},   {40, "XL"},
        {10, "X"},   {9, "IX"},
        {5, "V"},    {4, "IV"},
        {1, "I"}
    };

    string roman;
    for (auto &p : table) {
        while (x >= p.first) {
            roman += p.second;
            x -= p.first;
        }
    }

    return roman;
}

int roman_to_decimal(const string& roman) {
    int result = 0;

    for (int i = 0; i < roman.size(); ++i) {
        int now = roman_char_to_decimal(roman[i]);
        int next = 0;
        if (i + 1 < roman.size()) {
            next = roman_char_to_decimal(roman[i+1]);
        }

        if (now == -1 || next == -1) {
            return -1;
        }

        if (now < next) {
            result -= now;
        } else {
            result += now;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string roman1, roman2;
    cin >> roman1 >> roman2;

    const int a = roman_to_decimal(roman1);
    const int b = roman_to_decimal(roman2);

    cout << a + b << '\n';
    cout << decimal_to_roman(a + b) << '\n';

    return 0;
}