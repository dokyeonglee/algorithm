#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int dfs(set<int>& s, vector<int>& arr, int idx, int sum){

    if(idx == arr.size()){
        if(s.count(sum)){
            s.erase(sum);
            return 1;
        }else{
            return 0;
        }
    }

    int result = 0;
    int now = 0;

    while(idx < arr.size()){
        now = 10 * now + arr[idx];
        result += dfs(s, arr, idx + 1, sum + now);
        idx++;
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<int> arr;

        int temp = n;

        while(temp > 0){
            arr.push_back(temp % 10);
            temp /= 10;
        }
        
        int number_of_zero_or_one = count_if(arr.begin(), arr.end(),
                                        [](int& x) { return x <= 1; });

        if(number_of_zero_or_one == arr.size()){
            cout << "Hello, BOJ 2023!\n";
        }else{

            reverse(arr.begin(), arr.end());

            set<int> s;

            int answer = 0;

            vector<long long> pow_m(arr.size(), 1);

            while(1){
                long long sum = 0;
                for(int i = 0; i < arr.size(); i++){
                    pow_m[i] *= arr[i];
                    sum += pow_m[i];
                }
                if(sum > n){
                    break;
                }
                s.insert(sum);
            }

            cout << dfs(s, arr, 0, 0) << "\n";

        }
    }

    return 0;
}