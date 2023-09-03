#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;

    while(t--){

        priority_queue<int> pq;

        int q, k;
        cin >> q >> k;

        int now = 0;

        while(q--){
            string command;
            cin >> command;
            if(command[0] == 'p'){
                cout << now << "\n";
            }else{
                int x;
                cin >> x;
                now ^= x;
                pq.push(-x);
                if(pq.size() > k){
                    now ^= -pq.top();
                    pq.pop();
                }
            }
        }

    }

    return 0;
}