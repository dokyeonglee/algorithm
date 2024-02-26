#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        string t;
        cin >> t;
        arr[i] = stoi(t.substr(0, 2)) % 12 * 60 + stoi(t.substr(3));
    }

    int answer = n;

    for(int i = 1; i <= 720; i++){
        vector<bool> check(720);
        for(int j = 0; j < n - 1; j++){
            check[(arr[j] + (n - 1 - j) * i) % 720] = true;
        }
        check[arr.back()] = true;
        int result = 0;
        for(int j = 0; j < 720; j++){
            result += check[j];
        }
        answer = min(answer, result);
    }

    cout << answer;

    return 0;
}