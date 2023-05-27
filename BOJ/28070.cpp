#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> cnt(1000100);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string _a, _b;
        cin >> _a >> _b;
        int a = ((_a[0] - '0') * 1000 + (_a[1] - '0') * 100 + (_a[2] - '0') * 10 + (_a[3] - '0')) * 100 + ((_a[5] - '0') * 10 + (_a[6] - '0'));
        int b = ((_b[0] - '0') * 1000 + (_b[1] - '0') * 100 + (_b[2] - '0') * 10 + (_b[3] - '0')) * 100 + ((_b[5] - '0') * 10 + (_b[6] - '0'));
        cnt[a]++;
        cnt[b + 1]--;
    }

    int answer = 0;
    int idx = 0;
    for(int i = 200001; i <= 999912; i++){
        cnt[i] += cnt[i - 1];
        if(answer < cnt[i]){
            answer = cnt[i];
            idx = i;
        }
    }

    cout << idx / 100 << "-" << idx % 100 / 10 << idx % 100 % 10;

    return 0;
}