#include <iostream>
#include <queue>
#include <map>

using namespace std;

long long bfs(map<long long, bool>& check){

    queue<long long> q;
    q.push(1);

    int result = 1;

    int n = check.size();
    
    long long limit = (1ll << 60) - 1;

    while(!q.empty()){
        int sz = q.size();
        if(result >= n){
            return -1;
        }
        while(sz--){
            auto now = q.front();
            q.pop();
            if(now > limit){
                return -1;
            }
            if(!check[2 * now]){
                q.push(2 * now);
                result++;
            }
            if(!check[2 * now + 1]){
                q.push(2 * now + 1);
                result++;
            }
        }
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<long long, bool> check;

    while(n--){
        long long x;
        cin >> x;
        if(x == 1){
            cout << 0;
            return 0;
        }
        check[x] = true;
    }

    if(check[1]){
        cout << 0;
        return 0;
    }

    cout << bfs(check);

    return 0;
}