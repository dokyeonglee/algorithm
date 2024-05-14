#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

pair<int, int> get_direction(int x, int y){
    int g = gcd(abs(x), abs(y));
    x /= g;
    y /= g;
    return make_pair(x, y);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    pair<int, int> ballon_direction;

    vector<long long> hp(n);
    int x, y;

    for(int i = 0; i < n; i++){
        cin >> x >> y >> hp[i];
    }

    sort(hp.begin(), hp.end());

    ballon_direction = get_direction(x, y);
 
    long long sum = 0;    
    int idx = 0;

    for(int i = 0; i < m; i++){
        int d;
        cin >> x >> y >> d;
        auto attack_direction = get_direction(x, y);
        if(attack_direction == ballon_direction){
            sum += d;
            idx = upper_bound(hp.begin(), hp.end(), sum) - hp.begin();
        }
        cout << n - idx << "\n";
    }

    return 0;
}