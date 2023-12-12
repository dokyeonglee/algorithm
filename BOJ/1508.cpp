#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> arr(k);
    for(int& a : arr){
        cin >> a;
    }

    int left = 0;
    int right = n;
    string answer = "";

    while(left <= right){
        int mid = (left + right) / 2;
        int cnt = 1;
        int now = arr[0];
        string result(k, '0');
        result[0] = '1';
        while(cnt < m){
            auto it = upper_bound(arr.begin(), arr.end(), now + mid);
            if(it == arr.end()){
                break;
            }
            result[it - arr.begin()] = '1';
            now = *it;
            cnt++;
        }
        if(cnt == m){
            answer = result;
            left = mid + 1;
        }else{
            right = mid - 1;
        }

    }

    cout << answer;

    return 0;
}