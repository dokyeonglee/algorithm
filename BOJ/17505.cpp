#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, k;
    cin >> n >> k;

    vector<int> answer(n);

    int high = n;
    int low = 1;

    for(int i = 0; i < n; i++){
        if(n - i - 1 <= k){
            answer[i] = high--;
            k -= n - i - 1;
        }else{
            answer[i] = low++;
        }
    }

    for(auto& x : answer){
        cout << x << " ";
    }

    return 0;

}