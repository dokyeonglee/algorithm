#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    priority_queue<int> pq;
    priority_queue<int> pq2;

    while(n--){
        char c;
        int x;
        cin >> c >> x;
        if(c == 'T'){
            pq.emplace(-x);
        }else{
            pq2.emplace(-x);
        }
    }

    double current_time = 0;
    double current_distance = 0;
    int s = 1;

    while(!pq.empty() or !pq2.empty()){
        double time1 = 1e9;
        if(!pq.empty()){
            time1 = -pq.top();
        }
        double time2 = 1e9;
        if(!pq2.empty()){
            time2 = (-pq2.top() - current_distance) * s + current_time;
        }
        if(time1 < time2){
            current_distance += (time1 - current_time) / s;
            current_time = time1;
            pq.pop();
        }else{
            current_time = time2;
            current_distance = -pq2.top();
            pq2.pop();
        }
        s++;
    }

    current_time += (1000 - current_distance) * s;
    cout << (int)round(current_time);

    return 0;

}