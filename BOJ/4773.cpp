#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int roman_char_to_decimal(const char c) {
    if (c == 'I') {
        return 1;
    } else if (c == 'V') {
        return 5;
    } else if (c == 'X') {
        return 10;
    } else if (c == 'C') {
        return 100;
    } else if (c == 'M') {
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

    stack<int> st;
    while (!cin.eof()) {
        string str;
        cin >> str;

        if (str == "=") {
            if (st.empty()) {
                cout << "stack underflow\n";  
            } else if (st.top() < 1 || st.top() > 4999) {
                cout << "out of range exception\n";
            } else {
                cout << decimal_to_roman(st.top()) << '\n';
            }
        } else {
            const int x = roman_to_decimal(str);
            if (x == -1) {
                if (st.size() < 2) {
                    cout << "stack underflow\n";
                } else {
                    const int x = st.top();
                    st.pop();
                    
                    if (str == "+") {
                        st.top() += x;
                    } else if (str == "-") {
                        st.top() -= x;
                    } else if (str == "*") {
                        st.top() *= x;
                    } else if (str == "/") {
                        if (x == 0) {
                            cout << "division by zero exception\n";
                        } else {
                            st.top() /= x;
                        }
                    }
                }
            } else {
                st.push(x);
            }
        }
    }

    return 0;
}