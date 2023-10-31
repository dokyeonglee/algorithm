#include <iostream>
#include <vector>

using namespace std;

int msb(int x){
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x - (x >> 1);    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int now = arr[0];

    vector<pair<int, int>> temp;

    int cnt = 0;

    for(int i = 0; i < n; i++){
        if(now == arr[i]){
            cnt++;
        }else{
            temp.push_back(make_pair(now, cnt));
            now = arr[i];
            cnt = 1;
        }
    }

    temp.push_back(make_pair(now, cnt));

    if(temp.size() == 1){
        cout << msb(temp[0].second) * temp[0].first;
        return 0;
    }

    int answer = 1;

    int idx = 0;

    while(idx < temp.size()){
        int x = 0;
        if(idx > 0){
            x += temp[idx - 1].second / 2;
        }
        while(idx < temp.size() and (temp[idx].first == 2 or temp[idx].second % 2 == 0)){
            if(temp[idx].first == 1){
                x += temp[idx++].second / 2;
            }else{
                x += temp[idx++].second;
            }
        }
        if(idx < temp.size()){
            x += temp[idx++].second / 2;
        }
        answer = max(answer, msb(x) << 1);
    }

    cout << answer;

    return 0;
}