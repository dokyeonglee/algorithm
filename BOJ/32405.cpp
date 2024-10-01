#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> d(n + 1);
    vector<int> h(n + 1);
    vector<int> cnt(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }

    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }

    queue<int> q;

    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    int sum = 0;

    while(q.size() > 1){
        int now = q.front();
        q.pop();
        if(h[now] > sum - cnt[now] * d[now]){
            sum += d[now];
            cnt[now]++;
            q.push(now);
        }
    }
    
    cout << q.front();

    return 0;
}