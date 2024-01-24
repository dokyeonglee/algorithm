#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n, k;
        cin >> n >> k;
        
        priority_queue<pair<int, int>> pq;

        if(n == k){
            pq.emplace(-1, n);
        }else{
            pq.emplace(-1, k - 1);
            pq.emplace(-(n - k + 1), 1);
        }

        long long answer = 0;

        while(!pq.empty()){
            int x = -pq.top().first;
            int cnt = pq.top().second;
            pq.pop();
            if(cnt == 1){
                if(x == n){
                    break;
                }
                int y = -pq.top().first;
                int cnt2 = pq.top().second;
                pq.pop();
                pq.emplace(-(x + y), 1);
                answer += x + y;
                if(cnt2 > 1){
                    pq.emplace(-y, cnt2 - 1);
                }
            }else{
                answer += 2ll * x * (cnt / 2);
                pq.emplace(-2 * x, cnt / 2);
                if(cnt % 2 == 1){
                    pq.emplace(-x, 1);
                }
            }
        }

        cout << answer << "\n";
    }
    
    return 0;
}