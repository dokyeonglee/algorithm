#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int left = 1;
    int right = n;

    int answer = 0;
    
    while(left <= right){

        priority_queue<int> pq;

        int mid = (left + right) / 2;
        bool check = true;

        for(int i = 0; i < n; i++){
            if(i < mid){
                pq.push(-arr[i]);
            }else{
                int temp = -pq.top();
                pq.pop();
                if(temp + arr[i] > x){
                    check = false;
                    break;
                }
                pq.push(-(temp + arr[i]));
            }
        }

        if(check){
            answer = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }

    }

    cout << answer;

    return 0;
}