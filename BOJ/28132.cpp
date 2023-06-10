#include <iostream>
#include <vector>
#include <map>

using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> arr;

    long long answer = 0;

    long long cnt_00 = 0;
    long long cnt_01 = 0;
    long long cnt_10 = 0;

    map<pair<int, int>, int> cnt;

    for(int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        if(u == 0 and v == 0){
            cnt_00++;
        }else if(u == 0){
            cnt_01++;
        }else if(v == 0){
            cnt_10++;
        }else{
            int g = gcd(u, v);
            u /= g;
            v /= g;
            cnt[make_pair(u, v)]++;
            answer += cnt[make_pair(-v, u)];
            answer += cnt[make_pair(v, -u)];
        }
    }
    
    answer += cnt_00 * (cnt_00 - 1) / 2 + cnt_00 * (n - cnt_00);
    answer += cnt_01 * cnt_10;

    cout << answer;

    return 0;
}