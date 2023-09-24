#include <iostream>
#include <vector>
#include <bitset>

using namespace std;



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> temp;
    temp.reserve(n);

    for(int j = 19; j >= 0; j--){
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] & (1 << j)){
                temp.push_back(arr[i]);
            }
        }
        if(temp.size() >= k){
            arr = temp;
        }
        temp.clear();
    }

    int answer = arr[0];

    for(int i = 1; i < k; i++){
        answer &= arr[i];
    }

    cout << answer;


    return 0;
}