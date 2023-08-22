#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double f(vector<pair<int, int>>& arr, double q){
    double result = 0;
    for(int i = 0; i < arr.size(); i++){
        if(q < arr[i].first){
            result += arr[i].second / ((arr[i].first - q) * (arr[i].first - q));
        }else{
            result -= arr[i].second / ((arr[i].first - q) * (arr[i].first - q));
        }
    }
    return fabs(result);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
    }

    for(int i = 0; i < n; i++){
        cin >> arr[i].second;
    }

    sort(arr.begin(), arr.end());

    double left = arr[0].first;
    double right = arr[1].first;
    double answer = -1;

    while(fabs(right - left) > 1e-6){
        double p = (2 * left + right) / 3;
        double q = (left + 2 * right) / 3;
        if(f(arr, p) <= f(arr, q)){
            answer = q;
            right = q;
        }else{
            left = p;
        }
    }
    cout << fixed;
    cout.precision(10);
    cout << answer;

    return 0;
}