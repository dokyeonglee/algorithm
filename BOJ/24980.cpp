#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string str;
    cin >> str;

    int answer = 0;
    for (int i = n - 1; i >= 1; i-= 2) {
        if (str[i] != str[i - 1] && answer % 2 == (str[i] == 'G')) {
            ++answer;
        }
    }

    cout << answer << '\n';

    return 0;
}