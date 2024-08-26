#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h;
    cin >> h;

    priority_queue<int> pq;

    int n, q;
    cin >> n >> q;

    long long sum = 0;

    int x;

    while(n--){
        cin >> x;
        pq.push(-x);
        sum += x;
    }

    if(sum < h){
        cout << "-1\n";
    }else{
        while(!pq.empty() and sum + pq.top() >= h){
            sum += pq.top();
            pq.pop();
        }
        cout << pq.size() << "\n";
    }

    while(q--){
        cin >> x;
        sum += x;
        pq.push(-x);
        if(sum < h){
            cout << "-1\n";
        }else{
            while(!pq.empty() and sum + pq.top() >= h){
                sum += pq.top();
                pq.pop();
            }
            cout << pq.size() << "\n";
        }
    }

    return 0;
}