#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, s;
    cin >> n >> s;

    vector<long long> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    int left = s;
    int right = s;

    int next_left = s - 1;
    int next_right = s + 1;

    long long left_min_score = 0;
    long long right_min_score = 0;

    while(left >= 1 or right <= n){

        bool check = false;

        while(next_left >= 1 and arr[left - 1] - arr[next_left - 1] < 0){
            left_min_score = min(left_min_score, arr[left - 1] - arr[--next_left]);
        }

        if(next_left >= 1 and arr[left - 1] - arr[next_left - 1] >= 0 and -left_min_score <= arr[right] - arr[left - 1]){
            check = true;
            left = next_left--;
            left_min_score = 0;
        }

        while(next_right <= n and arr[next_right] - arr[right] < 0){
            right_min_score = min(right_min_score, arr[next_right++] - arr[right]);
        }

        if(next_right <= n and arr[next_right] - arr[right] >= 0 and -right_min_score <= arr[right] - arr[left - 1]){
            check = true;
            right = next_right++;
            right_min_score = 0;
        }

        if(!check){
            break;
        }

    }

    cout << arr[right] - arr[left - 1];

    return 0;
}