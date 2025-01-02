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

    for(auto& a : arr){
        int b;
        cin >> b;
        a = (a + b - 1) / b;
    }

    int left = 1;
    int right = 1e9;

    int answer;

    while(left <= right){
        int mid = (left + right) / 2;
        long long sum = 0;
        for(auto& a : arr){
            sum += max(0, a - mid);
        }
        if(sum <= mid){
            answer = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }

    cout << answer;

    return 0;

}