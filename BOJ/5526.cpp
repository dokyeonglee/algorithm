#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<int> brr;
    brr.reserve(arr.size() * arr.size());

    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr.size(); j++){
            brr.push_back(arr[i] + arr[j]);
        }
    }

    sort(brr.begin(), brr.end());

    int answer = 0;

    int left = 0;
    int right = brr.size() - 1;

    while(left <= right){
        if(brr[left] + brr[right] > m){
            right--;
        }else{
            answer = max(answer, brr[left] + brr[right]);
            left++;
        }
    }

    cout << answer;

    return 0;
}