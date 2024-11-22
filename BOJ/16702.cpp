#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int max_n = 1e6;

    vector<int> cnt(max_n + 1);

    for(int i = 1; i * i * i <= max_n; i++){
        for(int j = i + 1; i * j * j <= max_n; j++){
            for(int k = j + 1; i * j * k <= max_n; k++){
                cnt[i * j * k]++;
            }
        }
    }

    for(int i = 1; i < cnt.size(); i++){
        cnt[i] += cnt[i - 1];
    }

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        cout << cnt[n] << "\n";

    }

    return 0;
}