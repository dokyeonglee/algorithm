#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    const int mod = 1e9 + 7;

    long long answer = 1;

    for(int i = 2; i <= n; i++){
        answer = i * answer % mod;
    }

    cout << answer;

    return 0;
}