#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long sum = 0;

    vector<int> arr(n + 1);

    vector<int> v;
    vector<int> v2;
    
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        sum += arr[i];
        if(arr[i] == 0){
            v.push_back(i);
        }else{
            v2.push_back(i);
        }
    }

    if(sum != n - 1){
        cout << -1;
        return 0;
    }

    cout << v.back() << "\n";
    v.pop_back();

    while(!v2.empty()){
        cout << v2.back() << "\n";
        if(--arr[v2.back()] == 0){
            v.push_back(v2.back());
            v2.pop_back();
        }
        cout << v.back() << "\n";
        v.pop_back();
    }


    return 0;
}