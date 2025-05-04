#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for(auto& a : arr){
        cin >> a.second >> a.first;
    }

    sort(arr.begin(), arr.end());

    int x = 0;
    int y = 0;
    int answer = 0;

    for(auto& a : arr){
        if(a.second < x){
            continue;
        }
        if(a.second < y){
            x = y;
        }
        y = a.first;
        answer++;
    }

    cout << answer;

    return 0;

}