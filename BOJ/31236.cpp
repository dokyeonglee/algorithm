#include <iostream>
#include <vector>

using namespace std;

long long ccw(pair<long long, long long>& a, pair<long long, long long>& b, pair<long long, long long>& c){
    return (b.first - a.first) * (c.second - a.second)  - (c.first - a.first) * (b.second - a.second);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<long long, long long>> arr(n);
    for(auto& a : arr){
        cin >> a.first >> a.second;
    }

    int left = 0;
    int right = 1;

    int answer = 0;

    while(right < n - 1){
        if(ccw(arr[right], arr[right - 1], arr[right + 1]) < 0 and ccw(arr[right + 1], arr[right], arr[left]) < 0 and ccw(arr[left], arr[right + 1], arr[left + 1]) < 0){
            right++;
            answer = max(answer, right - left + 1);
        }else{
            if(++left == right){
                right++;
            }
        }
    }

    if(answer < 3){
        answer = -1;
    }

    cout << answer;

    return 0;
}