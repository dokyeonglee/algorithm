#include <iostream>
#include <vector>
#include <set>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, k;
    cin >> n >> k;

    set<pair<long long, long long>> s;

    for(long long i = 0; i < n; i++){
        long long a, b;
        cin >> a >> b;
        s.emplace(a, b);
    }

    long long x, y;
    cin >> x >> y;

    long long answer = abs(x) + abs(y);

    for(auto& p : s){
        answer = min(answer, abs(x - p.first) + abs(y - p.second) + 2);
        if(s.count(make_pair(x - p.first, y - p.second))){
            answer = min(answer, 4ll);
        }
        for(int i = 0; i < 4; i++){
            long long _x = x + dr[i];
            long long _y = y + dc[i];
            if(s.count(make_pair(_x - p.first, _y - p.second))){
                answer = min(answer, 5ll);
            }
        }
    }

    if(answer > k){
        answer = -1;
    }

    cout << answer;

    return 0;
}