#include <iostream>
#include <vector>

using namespace std;

bool possible(vector<int>& nearest_machine, int t, int k){

    int now = nearest_machine.size() - 1;

    while(k > 0){
        k--;
        now -= t;
        if(now <= 1){
            return true;
        }
        now = nearest_machine[now];
    }

    return false;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> nearest_machine(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> nearest_machine[i];
    }

    nearest_machine[n] = n;

    int idx = n;

    for(int i = n - 1; i >= 0; i--){
        if(nearest_machine[i]){
            idx = i;
        }
        nearest_machine[i] = idx;
    }

    int left = 1;
    int right = n - 1;

    int answer = n - 1;

    while(left <= right){
        int mid = (left + right) / 2;
        if(possible(nearest_machine, mid, k)){
            answer = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }

    cout << answer;

    return 0;
}