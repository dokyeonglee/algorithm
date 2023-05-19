#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    long long k;
    cin >> k;

    long long answer = 0;

    long long temp = 0;
    for(int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i + 1]){
            temp = max(temp, arr[i]);
            answer = 1;
        }
    }

    for(int i = 0; i < n; i++){
        long long diff = max(0ll, temp - arr[i]);
        arr[i] = max(arr[i], temp);
        if(k >= diff){
            k -= diff;
        }else{
            cout << 0;
            return 0;
        }
    }

    long long x = arr[0];
 
    for(int i = 0; i < n; i++){
        if(arr[i] > x){
            if(k >= (arr[i] - x) * i){
                k -= (arr[i] - x) * i;
                answer += arr[i] - x;
            }else{
                answer += k / i;
                break;
            }
            x = arr[i];
        }
    }

    answer += k / n;

    cout << answer;

    return 0;
}