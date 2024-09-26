#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    long long sum = 0;

    for(auto& a : arr){
        cin >> a;
        sum += a;
    }

    long long left = 1;
    long long right = sum / k;

    long long answer = 1;

    while(left <= right){
        long long mid = (left + right) / 2;
        long long number_of_current_assigned_group = 0;
        int number_of_people_in_group = 0;
        for(auto& a : arr){
            if(a >= mid){
                number_of_people_in_group++;
            }else{
                number_of_current_assigned_group += a;
                if(number_of_current_assigned_group >= mid){
                    number_of_current_assigned_group %= mid;
                    number_of_people_in_group++;
                }
            }
        }
        if(number_of_people_in_group >= k){
            answer = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    cout << answer;

    return 0;
}