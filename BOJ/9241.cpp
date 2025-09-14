#include <iostream>

using namespace std;

int calculate_common_prefix_length(const string& str1, const string& str2) {
    const int sz = min(str1.size(), str2.size());
    int i = 0;
    while (i < sz && str1[i] == str2[i]) {
        ++i;
    }
    return i;
}

int calculate_common_suffix_length(const string& str1, const string& str2) {
    int i = str1.size() - 1;
    int j = str2.size() - 1;
    int length = 0;

    while (i >= 0 && j >= 0 && str1[i] == str2[j]) {
        --i;
        --j;
        ++length;
    }

    return length;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string before;
    cin >> before;

    string after;
    cin >> after;

    const int common_prefix_length = calculate_common_prefix_length(before, after);
    const int common_suffix_length = calculate_common_suffix_length(before, after);
    const int inserted_length = max(0, (int)after.size() - common_prefix_length - common_suffix_length);

    cout << max((int)after.size() - (int)before.size(), inserted_length) << '\n';

    return 0;
}