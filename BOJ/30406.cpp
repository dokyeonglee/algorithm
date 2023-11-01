#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> cnt(4);

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }

    int answer = 0;

    int x = min(cnt[0], cnt[3]);

    answer += 3 * x;

    cnt[0] -= x;
    cnt[3] -= x;

    x = min(cnt[1], cnt[2]);

    answer += 3 * x;
    
    cnt[1] -= x;
    cnt[2] -= x;

    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 4; j++){
            x = min(cnt[i], cnt[j]);
            answer += (i ^ j) * x;
            cnt[i] -= x;
            cnt[j] -= x;
        }
    }

    cout << answer;

    return 0;
}