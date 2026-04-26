#include <iostream>
#include <vector>

using namespace std;

bool is_upper(char c) {
    return c >= 'A' && c <= 'Z';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    bool caps_lock = false;
    int answer = 0;
    for (int i = 0; i < str.size() - 1; ++i) {
        if (is_upper(str[i]) == caps_lock) {
            ++answer;
        } else if (is_upper(str[i + 1]) != caps_lock) {
            answer += 2;
            caps_lock ^= true;
        } else {
            answer += 2;
        }
    }

    if (is_upper(str.back()) == caps_lock) {
        ++answer;
    } else {
        answer += 2;
    }

    cout << answer;

    return 0;
}