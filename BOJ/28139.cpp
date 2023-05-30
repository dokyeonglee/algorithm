#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double get_distance(pair<int, int>& a, pair<int, int>& b){
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    double answer = 0;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            answer += get_distance(arr[i], arr[j]);
        }
    }

    answer *= 2;
    answer /= n;
    
    cout.precision(10);
    cout << answer;

    return 0;
}