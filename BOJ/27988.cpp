#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool can_knot(pair<int, int>& a, pair<int, int>& b){
    return abs(a.first - b.first) <= a.second + b.second;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<pair<int, int>, pair<char, int>>> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i].first.first;
    }

    for(int i = 0; i < n; i++){
        cin >> arr[i].first.second;
    }

    for(int i = 0; i < n; i++){
        cin >> arr[i].second.first;
    }

    for(int i = 0; i < n; i++){
        arr[i].second.second = i + 1;
    }

    sort(arr.begin(), arr.end());

    string str = "RYB";
    vector<int> indices(3, -1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            if(arr[i].second.first == str[j]){
                if(indices[j] == -1 or arr[indices[j]].first.first + arr[indices[j]].first.second <= arr[i].first.first + arr[i].first.second){
                    indices[j] = i;
                }
                if(indices[(j + 1) % 3] != -1){
                    if(can_knot(arr[i].first, arr[indices[(j + 1) % 3]].first)){
                        cout << "YES\n";
                        cout << arr[i].second.second << " " << arr[indices[(j + 1) % 3]].second.second;
                        return 0;
                    }
                }
                if(indices[(j + 2) % 3] != -1){
                    if(can_knot(arr[i].first, arr[indices[(j + 2) % 3]].first)){
                        cout << "YES\n";
                        cout << arr[i].second.second << " " << arr[indices[(j + 2) % 3]].second.second;
                        return 0;
                    }
                }
                break;
            }
        }
    }

    cout << "NO";

    return 0;
}