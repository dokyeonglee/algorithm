#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> brr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        cin >> brr[i];
    }

    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());

    int answer = 0;

    if(arr.front() > brr.back()){
        cout << 100 * n;
        return 0;
    }

    int a_front = 0;
    int a_back = n - 1;
    
    int b_front = 0;
    int b_back = n - 1;

    while(a_front <= a_back){
        if(arr[a_front] > brr[b_front]){
            answer += 100;
            ++a_front;
            ++b_front;
        }else if(arr[a_back] > brr[b_back]){
            answer += 100;
            --a_back;
            --b_back;
        }else if(arr[a_front] < brr[b_back]){
            answer -= 50;
            ++a_front;
            --b_back;
        }else if(arr[a_front] == brr[b_back]){
            answer += 20;
            ++a_front;
            --b_back;
        }
    }

    cout << answer;

    return 0;
}