#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool possible(vector<string>& arr, int x){

    set<string> check;

    for(int i = 0; i < arr[0].size(); i++){
        string str = "";
        for(int j = x; j < arr.size(); j++){
            str += arr[j][i];
        }
        if(check.count(str)){
            return false;
        }
        check.insert(str);
    }

    return true;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;

    vector<string> arr(r);
    for(auto& a : arr){
        cin >> a;
    }

    int left = 0;
    int right = r - 1;

    int answer = 0;

    while(left <= right){
        int mid = (left + right) / 2;
        if(possible(arr, mid)){
            left = mid + 1;
            answer = mid;
        }else{
            right = mid - 1;
        }
    }

    cout << answer;

    return 0;
}