#include <iostream>
#include <vector>

using namespace std;

long long max_time(vector<int>& arr, int idx){
    long long result = 0;
    for(int i = 0; i < arr.size(); i++){
        result = max(result, 1ll * abs(idx - i) * arr[i]);
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto& a : arr){
        cin >> a;
    }

    int left = 0;
    int right = n - 1;

    while(right - left >= 3){
        int p1 = (2 * left + right) / 3;
        int p2 = (left + 2 * right) / 3;
        if(max_time(arr, p1) <= max_time(arr, p2)){
            right = p2;
        }else{
            left = p1;
        }
    }

    long long answer = 1e18;

    for(int i = left; i <= right; i++){
        answer = min(answer, max_time(arr, i));
    }

    cout << answer;

    return 0;
}