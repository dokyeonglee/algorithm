#include <iostream>
#include <vector>

using namespace std;

void hanoi(int n, int from, int by, int to){
    if(n == 0){
        return;
    }
    hanoi(n - 1, from, to, by);
    cout << from << " " << to << "\n";
    hanoi(n - 1, by, from, to);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if(n <= 63){
        cout << (1ull << n) - 1 << "\n";
    }else{
        __int128 cnt = (1ull << 63);
        cnt *= (1ull << (n - 63));
        cnt--;
        const long long mod = 1e18;
        vector<long long> ans;
        while(cnt > 0){
            ans.push_back(cnt % mod);
            cnt /= mod;
        }
        for(int i = ans.size() - 1; i >= 0; i--){
            cout << ans[i];
        }
        
    }

    if(n <= 20){
        hanoi(n, 1, 2, 3);
    }

    return 0;
}