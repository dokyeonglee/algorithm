#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<long long> fac(21);
    fac[0] = 1;

    for(int i = 1; i <= 20; i++){
        fac[i] = i * fac[i - 1];
    }

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;
        if(k == 1){
            cout << fac[n - 1] << "\n";
        }else{
            long long answer = 0;
            for(int i = 2; i <= k; i++){
                answer += (i - 1) * fac[n - i] / fac[k - i];
            }
            answer *= fac[k - 2];
            cout << answer << "\n";
        }
    }

    return 0;
}