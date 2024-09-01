#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> psum(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> psum[i];
        psum[i] += psum[i - 1];
    }

    if(n == 1){
        cout << psum[1] << "\n";
        cout << "1 1";
        return 0;
    }

    vector<pair<long long, int>> arr(n + 1);

    for(int i = 1; i <= n; i++){
        arr[i] = make_pair(psum[i], i);
    }

    sort(arr.begin() + 1, arr.end());

    long long answer = 1e18;

    int left = -1;
    int right = -1;

    for(int i = 1; i <= n; i++){
        if(abs(arr[i].first) < answer){
            left = 1;
            right = arr[i].second;
            answer = abs(arr[i].first);           
        }
    }

    for(int i = 2; i <= n; i++){
        auto temp = min(answer, abs(arr[i].first - arr[i - 1].first));
        if(temp < answer){
            left = arr[i - 1].second;
            right = arr[i].second;
           answer = temp;
           if(left < right){
                left++;
           }else{
                right++;
           }
        }
    }

    if(left > right){
        swap(left, right);
    }

    answer = psum[right] - psum[left - 1];

    cout << psum[right] - psum[left - 1] << "\n";
    cout << left << " " << right;

    return 0;
}