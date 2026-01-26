#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> mat_mul(const vector<vector<int>>& arr, const vector<vector<int>>& brr, const int mod) {
    vector<vector<int>> result(arr.size(), vector<int>(brr[0].size()));
    for (int k = 0; k < arr[0].size(); ++k) {
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = 0; j < brr[0].size(); ++j) {
                result[i][j] = (result[i][j] + arr[i][k] * brr[k][j]) % mod;
            }
        }
    }

    return result;
}

vector<vector<int>> mat_pow(vector<vector<int>>& arr, int n, int mod) {
    vector<vector<int>> result(arr.size(), vector<int>(arr[0].size()));
    for (int i = 0; i < result.size(); ++i) {
        result[i][i] = 1;
    }

    while (n > 0) {
        if (n & 1) {
            result = mat_mul(result, arr, mod);
        }
        arr = mat_mul(arr, arr, mod);
        n >>= 1;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        int n, m, p;
        cin >> n >> p >> m;

        if (n == 0) {
            break;
        }

        vector<vector<int>> arr(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> arr[i][j];
            }
        }

        auto answer = mat_pow(arr, m, p);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << answer[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }

    return 0;
}