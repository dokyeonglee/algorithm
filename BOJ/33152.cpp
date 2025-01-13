#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i].first;
            arr[i].second = i;
        }

        if(n < 3){
            cout << "NO\n";
            continue;
        }

        sort(arr.begin(), arr.end());

        vector<int> answer(n);
        vector<int> answer2(n);

        long long total_votes_of_x = 0;
        long long total_votes_of_y = 0;

        for(int i = 0; i < n / 2 + 1; i++){
            answer[arr[i].second] += arr[i].first - arr[i].first / 2 - 1;
            answer2[arr[i].second] += arr[i].first / 2 + 1;
            total_votes_of_x += arr[i].first - arr[i].first / 2 - 1;
            total_votes_of_y += arr[i].first / 2 + 1;
        }

        for(int i = n / 2 + 1; i < n; i++){
            total_votes_of_x += arr[i].first;
            answer[arr[i].second] += arr[i].first;
        }

        bool possible = true;

        if(total_votes_of_x <= total_votes_of_y){
            possible = false;
            if(n % 2 == 0 and total_votes_of_x + 2 > total_votes_of_y){
                for(int i = 0; i < n / 2 + 1; i++){
                    if(arr[i].first % 2 == 0){
                        answer[arr[i].second] = arr[i].first / 2;
                        answer2[arr[i].second] = arr[i].first / 2;
                        possible = true;
                        break;
                    }
                }
            }
        }

        if(possible){
            cout << "YES\n";
            for(int i = 0; i < n; i++){
                cout << answer[i] << " ";
            }
            cout << "\n";
            for(int i = 0; i < n; i++){
                cout << answer2[i] << " ";
            }
            cout << "\n";
        }else{
            cout << "NO\n";
        }


    }

    return 0;

}