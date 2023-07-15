#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, s;
    cin >> n >> s;

    vector<int> x(n + 5);
    vector<int> h(n + 5);

    for(int i = 1; i <= n; i++){
        cin >> x[i];
    }

    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }

    int left = x[s] - h[s];
    int right = x[s] + h[s];
    int left_idx = s;
    int right_idx = s;
    
    while(1){
        bool check = true;
        if(left_idx > 1 and (left <= x[left_idx - 1] or x[left_idx] - x[left_idx - 1] <= h[left_idx])){
            left = min(left, x[left_idx] - h[left_idx]);
            right = max(right, x[left_idx] + h[left_idx--]);
            check = false;
        }
        if(right_idx < n and (right >= x[right_idx + 1] or x[right_idx + 1] - x[right_idx] <= h[right_idx])){
            left = min(left, x[right_idx] - h[right_idx]);
            right = max(right, x[right_idx] + h[right_idx++]);
            check = false;
        }
        if(check){
            break;
        }
    }

    for(int i = left_idx; i <= right_idx; i++){
        cout << i << " ";
    }

    return 0;
}