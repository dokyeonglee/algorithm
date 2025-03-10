#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> arr(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin() + 1, arr.end(), 
        [](pair<int, int>& a, pair<int, int>& b){
        return a.first - a.second < b.first - b.second;
    });

    vector<long long> a_psum(n + 1);
    vector<long long> b_psum(n + 1);

    for(int i = 1; i <= n; i++){
        a_psum[i] = a_psum[i - 1] + arr[i].first;
        b_psum[i] = b_psum[i - 1] + arr[i].second;
    }

    long long add_to_a = 0;
    long long add_to_b = 0;

    int q;
    cin >> q;

    while(q--){
        char c;
        int x;
        cin >> c >> x;
        if(c == 'A'){
            add_to_a += x;
        }else if(c == 'B'){
            add_to_b += x;
        }
        int idx = lower_bound(arr.begin() + 1, arr.end(), add_to_b - add_to_a,
                                [](pair<int, int>& a, long long x){
                                    return a.first - a.second < x;
                                }) - arr.begin() - 1;
        long long result = b_psum[idx] + idx * add_to_b + (a_psum[n] - a_psum[idx]) + (n - idx) * add_to_a;
        cout << result << "\n";
    }

    return 0;

}