#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test_case = 1;

    while(1){

        int n;
        cin >> n;

        if(n == 0){
            break;
        }

        vector<pair<int, int>> arr(n);
        vector<bool> check(32);

        for(auto& a : arr){
            cin >> a.second >> a.first;
            a.first = 2 * (a.first - 8);
            a.second = 2 * (a.second - 8);
        }

        sort(arr.begin(), arr.end());

        int answer = 0;

        for(int i = 0; i < n; i++){
            for(int j = arr[i].second; j < arr[i].first; j++){
                if(!check[j]){
                    check[j] = true;
                    answer++;
                    break;
                }
            }
        }

        cout << "On day " << test_case++ << " Emma can attend as many as " << answer << " parties.\n";

    }

    return 0;

}