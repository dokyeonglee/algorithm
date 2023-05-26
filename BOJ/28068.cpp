#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue<pair<int, int>> pq;
    priority_queue<pair<int, int>> pq2;
    
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(a <= b){ 
            pq.push(make_pair(-a, b));
        }
        else{
            pq2.push(make_pair(b, a));
        }
    }

    long long fun = 0;
    while(!pq.empty()){
        int a = -pq.top().first;
        int b = pq.top().second;
        pq.pop();
        if(fun < a){
            cout << 0;
            return 0;
        }
        fun += b - a;
    }

    while(!pq2.empty()){
        int b = pq2.top().first;
        int a = pq2.top().second;
        pq2.pop();
        if(fun < a){
            cout << 0;
            return 0;
        }
        fun += b - a;
    }

    cout << 1;

    return 0;
}