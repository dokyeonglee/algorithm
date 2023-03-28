#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, atk;
    cin >> n >> atk;

    vector<pair<int, pair<int, int>>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second.first >> arr[i].second.second;
    }

    long long left = 0;
    long long right = 1e18;
    long long answer = 0;

    while(left <= right){

        long long mid = (left + right) / 2;
        long long curr_hp = mid;
        long long curr_atk = atk;

        for(int i = 0; i < n; i++){
            if(arr[i].first == 1){

                int monster_atk = arr[i].second.first;
                int monster_hp = arr[i].second.second;

                if(((monster_hp - 1) / curr_atk) * monster_atk < curr_hp){
                    curr_hp -= ((monster_hp - 1) / curr_atk) * monster_atk;
                }else{
                    curr_hp = -1;
                    break;
                }
                
            }else{
                curr_atk += arr[i].second.first;
                curr_hp = min(curr_hp + arr[i].second.second, mid);
            }
        }

        if(curr_hp > 0){
            answer = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }

    }

    cout << answer;

    return 0;
}