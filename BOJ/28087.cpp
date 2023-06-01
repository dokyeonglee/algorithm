#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<bool> check(m + 1);

    int cnt = 0;
    long long sum = 0;

    for(int i = 1; i <= m; i++){
        int x;
        cin >> x;
        if(x >= n and x <= 2 * n){
            cout << 1 << "\n" << i;
            return 0;
        }
        if(sum + x <= 2 * n){
            check[i] = true;
            sum += x;
            cnt++;
        }
        if(sum >= n and sum <= 2 * n){
            break;
        }
    }

    cout << cnt << "\n";
    for(int i = 1; i <= m; i++){
        if(check[i]){
            cout << i << "\n";
        }
    }

    return 0;
}