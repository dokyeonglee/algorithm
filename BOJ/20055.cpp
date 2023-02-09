#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    deque<int> dq(2 * n);
    deque<bool> robots(2 * n);

    for(int i = 0; i < 2 * n; i++){
        cin >> dq[i];
    }

    int answer = 0;
    int cnt = 0;

    while(cnt < k){

        answer++;

        dq.push_front(dq.back());
        dq.pop_back();

        robots.push_front(robots.back());
        robots.pop_back();

        robots[n - 1] = false;

        for(int i = n - 2; i >= 0; i--){
            if(!robots[i + 1] and dq[i + 1] > 0 and robots[i]){
                robots[i] = false;
                robots[i + 1] = true;
                dq[i + 1]--;
            }
        }

        robots[n - 1] = false;

        if(!robots[0] and dq[0] > 0){
            robots[0] = true;
            dq[0]--;
        }

        cnt = 0;

        for(int i = 0; i < 2 * n; i++){
            if(dq[i] == 0){
                cnt++;
            }
        }

    }

    cout << answer;

    return 0;
}