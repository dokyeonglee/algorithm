#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
int solve(vector<int>& arr, vector<int>& brr, vector<int>& crr){

    int result = 1e9;

    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < brr.size(); j++){
            int min_value = min(arr[i], brr[j]);
            int max_value = max(arr[i], brr[j]);
            auto it = lower_bound(crr.begin(), crr.end(), min_value);
            auto it2 = lower_bound(crr.begin(), crr.end(), max_value);
            if(it != crr.end()){
                if(*it <= max_value){
                    result = min(result, max_value - min_value);
                }
            }
        }
    }

    return result;

}
*/
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    vector<int> arr(a);
    vector<int> brr(b);
    vector<int> crr(c);

    for(auto& a : arr){
        cin >> a;
    }

    for(auto& b : brr){
        cin >> b;
    }

    for(auto& c : crr){
        cin >> c;
    }

    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
    sort(crr.begin(), crr.end());

    int answer = 1e9;

    for(int i = 0; i < a; i++){
        auto it = lower_bound(brr.begin(), brr.end(), arr[i]);
        auto it2 = lower_bound(crr.begin(), crr.end(), arr[i]);
        if(it != brr.end() and it2 != crr.end()){
            answer = min(answer, max(*it, *it2) - arr[i]);
        }
        if(it2 != crr.end() and it != brr.begin()){
            answer = min(answer, *it2 - *(it - 1));
        }
        if(it != brr.end() and it2 != crr.begin()){
            answer = min(answer, *it - *(it2 - 1));
        }
        if(it != brr.begin() and it2 != crr.begin()){
            answer = min(answer, arr[i] - min(*(it - 1), *(it2 - 1)));
        }
    }

    cout << answer;

    return 0;
}