#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        int n;
        cin >> n;
        if(n == 0){
            break;
        }else{
            queue<long long> q;
            q.push(1ll);
            while(!q.empty()){
                long long x = q.front();
                q.pop();
                if(x % n == 0){
                    cout << x << "\n";
                    break;
                }
                q.push(x * 10);
                q.push(x * 10 + 1);
            }
        }
    }

    return 0;
}