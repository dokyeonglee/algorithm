#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<long long> cow(n);
    vector<int> candy(m);

    for(auto& c : cow){
        cin >> c;
    }

    for(auto& c : candy){
        cin >> c;
    }

    for(int i = 0; i < m; i++){
        long long h = 0;
        for(int j = 0; j < n; j++){
            if(candy[i] <= h){
                break;
            }
            if(cow[j] <= h){
                continue;
            }
            int eat = min((long long)candy[i], cow[j]) - h;
            h = cow[j];
            cow[j] += eat;
        }
    }

    for(auto& c : cow){
        cout << c << ' ';
    }

    return 0;
}