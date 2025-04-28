#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr;

    int k;

    for(int i = 1; i < n; i++){
        cout << i << " " << 1 << endl;
        cin >> k;
        arr.push_back(k);
    }

    int r = n - 1;

    for(int i = 1; i < arr.size() - 1; i++){
        if(arr[i - 1] == arr[i + 1]){
            r = i + 1;
            break;
        }
    }

    for(int i = 2; i < n; i++){
        int x = (r - 1 + i - 1) ^ arr[0];
        bool check = true;
        for(int j = 1; j < arr.size(); j++){
            if(((abs(r - j - 1) + i - 1) ^ arr[j]) != x){
                check = false;
                break;
            }
        }
        if(check){
            cout << r << " " << i << endl;
            cin >> k;
            return 0;
        }
    }

    return 0;

}