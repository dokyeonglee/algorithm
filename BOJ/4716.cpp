#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b){
    return abs(a.second.first - a.second.second) > abs(b.second.first - b.second.second);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1){

        int n, a, b;
        cin >> n >> a >> b;

        if(n == 0){
            break;
        }

        vector<pair<int, pair<int, int>>> arr(n);
        for(auto& p : arr){
            cin >> p.first >> p.second.first >> p.second.second;
        }

        sort(arr.begin(), arr.end(), compare);

        int answer = 0;

        for(auto& p : arr){
            int from_a;
            int from_b;
            if(p.second.first < p.second.second){
                from_a = min(a, p.first);
                from_b = p.first - from_a;
            }else{
                from_b = min(b, p.first);
                from_a = p.first - from_b;
            }
            answer += from_a * p.second.first + from_b * p.second.second;
            a -= from_a;
            b -= from_b;
        }

        cout << answer << "\n";

    }

    return 0;

}