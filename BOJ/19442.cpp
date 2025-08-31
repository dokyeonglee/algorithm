#include <iostream>

using namespace std;

int max_shortest_palindrome_length(const int total_chars, const int odd_types) {
    const int min_palindromes = max(odd_types, 1);

    if (min_palindromes == 1) {
        return total_chars;
    }

    int leftover_pairs = (total_chars - min_palindromes) / 2;

    return leftover_pairs / min_palindromes * 2 + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int total_chars = 0;
        int odd_types = 0;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            total_chars += x;
            odd_types += x % 2;
        }

        cout << max_shortest_palindrome_length(total_chars, odd_types) << '\n';        
    }

    return 0;
}