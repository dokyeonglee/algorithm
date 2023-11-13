#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> cnt(721);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        cnt[a + 180 - b]++;
        cnt[a + 181 + b]--;
    }

    int answer = 0;

    for(int i = 1; i <= 720; i++){
        cnt[i] += cnt[i - 1];
    }

    for(int i = 0; i < 360; i++){
        if(cnt[i] or cnt[i + 360]){
            answer++;
        }
    }

    cout << answer;

    return 0;
}