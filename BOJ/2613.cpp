#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for(auto& a : arr){
        cin >> a;
    }

    int left = *max_element(arr.begin(), arr.end());
    int right = 30000;

    int answer;

    while(left <= right){
        int mid = (left + right) / 2;
        int cnt = 1;
        int sum = 0;
        for(int& a : arr){
            if(sum + a <= mid){
                sum += a;
            }else{
                sum = a;
                cnt++;
            }
        }
        if(cnt <= m){
            answer = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }

    cout << answer << "\n";

    vector<int> v;

    int sum = 0;

    int cnt = 0;

    for(int i = 0; i < n; i++){
        if(sum + arr[i] <= answer){
            sum += arr[i];
            cnt++;            
        }else{
            sum = arr[i];
            v.push_back(cnt);
            cnt = 1;
        }
    }

    v.push_back(cnt);

    int d = m - v.size();

    for(auto& x : v){
        while(x > 1 and d > 0){
            cout << "1 ";
            x--;
            d--;
        }
        cout << x << " ";
    }

    return 0;
}