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

    long long p, q, r, s;
    cin >> p >> q >> r >> s;

    long long answer = 1e18;
    
    long long left = 1;
    long long right = 1e18;

    while(left <= right){

        auto mid = (left + right) / 2;
        long long score = 0;

        for(int i = 0; i < n; i++){
            if(arr[i] > mid + r){
                score += arr[i] - p;
            }else if(arr[i] < mid){
                score += arr[i] + q;
            }else{
                score += arr[i];
            }
        }

        if(score >= s){
            answer = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }

    }

    if(answer == 1e18){
        answer = -1;
    }

    cout << answer;

    return 0;
}