#include <iostream>
#include <vector>

using namespace std;

long long x, n;

long long calculate_final_water(vector<long long>& arr, long long mid){
    long long result = mid;
    for(long long& a : arr){
        result = min(x, max(0ll, result + a));
    }
    return result;
}

long long min_water_to_target_water(vector<long long>& arr, long long target_water){

    long long left = 0;
    long long right = x;
    long long result = 0;

    while(left <= right){
        long long mid = (left + right) / 2;
        long long final_water = calculate_final_water(arr, mid);
        if(final_water < target_water){
            left = mid + 1;
        }else{
            result = mid;
            right = mid - 1;
        }
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //long long x, n;
    cin >> x >> n;

    vector<long long> arr(n);
    for(long long& a : arr){
        cin >> a;
    }

    long long min_final_water = calculate_final_water(arr, 0);
    long long max_final_water = calculate_final_water(arr, x);

    long long max_water_to_min_final_water = max(0ll, min_water_to_target_water(arr, min(max_final_water, min_final_water + 1)) - 1);
    long long min_water_to_max_final_water = min_water_to_target_water(arr, max_final_water);

    int q;
    cin >> q;

    while(q--){
        long long water;
        cin >> water;
        if(water <= max_water_to_min_final_water){
            cout << min_final_water << "\n";
        }else if(water >= min_water_to_max_final_water){
            cout << max_final_water << "\n";
        }else{
            cout << min_final_water + water - max_water_to_min_final_water << "\n";
        }
    }

    return 0;
}