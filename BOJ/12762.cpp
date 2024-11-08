#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto& a : arr){
        cin >> a;
    }

    vector<int> down(n);
    vector<int> up(n);

    vector<int> v(1, -10001);

    for(int i = 0; i < n; i++){
        if(v.back() < -arr[i]){
            v.push_back(-arr[i]);
            down[i] = v.size() - 1;
        }else{
            auto it = lower_bound(v.begin(), v.end(), -arr[i]);
            *it = -arr[i];
            down[i] = it - v.begin();
        }
    }

    v.clear();
    v.push_back(-10001);

    for(int i = n - 1; i >= 0; i--){
        if(v.back() < -arr[i]){
            v.push_back(-arr[i]);
            up[i] = v.size() - 1;
        }else{
            auto it = lower_bound(v.begin(), v.end(), -arr[i]);
            *it = -arr[i];
            up[i] = it - v.begin();
        }
    }

    int answer = 0;

    for(int i = 0; i < n; i++){
        answer = max(answer, down[i] + up[i] - 1);
    }

    cout << answer;

    return 0;
}