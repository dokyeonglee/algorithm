#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    vector<bool> check(1e6 + 1);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        check[arr[i]] = true;
    }

    vector<int> answer(1e6 + 1);

    for(int& i : arr){
        for(int j = i; j <= 1e6; j += i){
            if(check[j]){
                answer[i]++;
                answer[j]--;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << answer[arr[i]] << " ";
    }

    return 0;
}