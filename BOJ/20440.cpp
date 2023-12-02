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

    int s = -1;
    int e = 0;
    int cnt = 0;

    int answer = 0;

    for(int i = 0; i < arr.size();){
        int j = i;  
        for(; i < arr.size() and arr[j].first == arr[i].first; i++){
            cnt += arr[i].second;
        }
        if(answer < cnt){
            answer = cnt;
            s = arr[j].first;
            e = 0;
        }else if(answer > cnt and !e){
            e = arr[i - 1].first;
        }
    }

    cout << answer << "\n" << s << " " << e;
    

    return 0;
}