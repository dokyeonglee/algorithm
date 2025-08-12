#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void arrange_for_max_goods(vector<int>& passwords) {
    sort(passwords.begin(), passwords.end());
}

int calculate_max_goods(const vector<int>& passwords) {
    const int n = passwords.size();

    if (passwords[n - 1] == 0) {
        return 0;
    }

    int mex = 0;

    for (const int password : passwords) {
        if (password == mex) {
            ++mex;
        } else if (password > mex) {
            break;
        }
    }

    return mex + 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> passwords(n);
    for (int& password : passwords) {
        cin >> password;
    }

    arrange_for_max_goods(passwords);

    int max_goods = calculate_max_goods(passwords);

    cout << max_goods << '\n';
    for (const int password : passwords) {
        cout << password << ' ';
    }

    return 0;
}