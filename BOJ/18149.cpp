#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    priority_queue<int> pq;

    while(t--){

        int n;
        cin >> n;

        while(n--){
            int x;
            cin >> x;
            pq.push(-x);
        }

        int answer = 0;
        
        while(pq.size() > 1){
            int x = -pq.top(); pq.pop();
            int y = -pq.top(); pq.pop();
            answer += x + y;
            pq.push(-(x + y));
        }
        pq.pop();

        cout << answer << "\n";

    }

    return 0;

}