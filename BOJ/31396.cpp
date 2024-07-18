#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, m;
    cin >> n >> k >> m;

    vector<int> arr(n);
    vector<int> d(m);
    vector<int> cnt(200002);

    for(int& a : arr){
        cin >> a;
    }

    for(int& x : d){
        cin >> x;
        cnt[++x]++;
    }

    sort(arr.rbegin(), arr.rend());
    sort(d.begin(), d.end());

    vector<int> psum(200002);

    //psum[0] = cnt[0];

    for(int i = 1; i <= 200001; i++){
        psum[i] = psum[i - 1] + cnt[i];
    }

    int left = k;
    int right = m;
    int answer = k;

    while(left <= right){

        int mid = (left + right) / 2;
        int power_strip_idx = 0;
        int distance = 1;
        long long socket = k;
        int i = m - mid;
        bool check = true;

        cnt[d[i]] = psum[d[i]] - i;

        while(i < m){
            if(distance == d[i]){
                if(socket < cnt[d[i]]){
                    check = false;
                    break;
                }
                socket -= cnt[d[i]];
                i += cnt[d[i]];
            }
            long long temp = 0;
            while(power_strip_idx < n and socket > 0){
                temp += arr[power_strip_idx++];
                socket--;
            }
            if(socket == 0){
                socket = temp;
                distance++;
            }else{
                check = (socket + temp >= m - i);
                break;
            }
        }
       
        if(check){
            answer = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }

        cnt[d[i]] = psum[d[i]] - psum[d[i] - 1];

    }

    cout << answer;

    return 0;
}