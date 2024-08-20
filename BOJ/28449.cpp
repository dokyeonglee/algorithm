#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for(auto& a : arr){
        cin >> a;
    }

    vector<int> cnt(1e5 + 1);

    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }

    for(int i = 1; i < cnt.size(); i++){
        cnt[i] += cnt[i - 1];
    }

    long long hi = 0;
    long long arc = 0;
    long long draw = 0;

    for(int& a : arr){
        hi += cnt[a - 1];
        draw += cnt[a] - cnt[a - 1];
        arc += m - cnt[a];
    }

    cout << hi << " " << arc << " " << draw;

    return 0;
}