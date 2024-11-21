#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    int left = 1;
    int right = n;

    long long answer = 0;

    int now = 1;

    while(left < right){
        while(left < n and arr[left] == 0){
            left++;
        }
        while(right > 1 and arr[right] == 0){
            right--;
        }
        if(left < right){
            int m = min(arr[left], arr[right]);
            answer += (left - now + n) % n;
            answer += 1ll * (2 * m - 1) * (n - (right - left));
            arr[left] -= m;
            arr[right] -= m;
            now = right;
        }
    }

    if(arr[left]){
        if(now != left){
            answer += (left - now + n) % n;
            arr[left]--;
        }
        answer += n * arr[left];
    }

    cout << answer;

    return 0;
}