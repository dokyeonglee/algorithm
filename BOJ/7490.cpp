#include <iostream>
#include <vector>

using namespace std;

void dfs(int sum, int sign, int x, int now, int n, string s) {
    if(now == n){
        sum += sign * x;
        if(sum == 0){
            cout << s << "\n";
        }
        return;
    }
    dfs(sum, sign, x * 10 + now + 1, now + 1, n, s + ' ' + char(now + 49));
    dfs(sum + sign * x, 1, now + 1, now + 1, n, s + '+' + char(now + 49));
    dfs(sum + sign * x, -1, now + 1, now + 1, n, s + '-' + char(now + 49));
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        
        dfs(0, 1, 1, 1, n, "1");
        cout << "\n";

    }

    return 0;
}