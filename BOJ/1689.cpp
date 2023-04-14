#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> arr(2 * n);

    for(int i = 0; i < 2 * n; i += 2){
        int s, e;
        cin >> s >> e;
        arr[i] = make_pair(s, 1);
        arr[i + 1] = make_pair(e, -1);
    }

    sort(arr.begin(), arr.end());

    int answer = 0;
    int cnt = 0;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i].second == 1){
            cnt++;
        }else{
            cnt--;
        }
        answer = max(answer, cnt);
    }

    cout << answer;

    return 0;
}