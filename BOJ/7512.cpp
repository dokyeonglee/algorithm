#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> is_prime(1e7, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i * i <= (1e7) ; i++){
        if(is_prime[i]){
            for(int j = i * i; j <= (1e7); j += i){
                is_prime[j] = false;
            }
        }
    }

    vector<int> prime;
    prime.reserve(7e5);

    prime.push_back(2);

    for(int i = 3; i <= 1e7; i += 2){
        if(is_prime[i]){
            prime.push_back(i);
        }
    }

    int t;
    cin >> t;

    for(int test_case = 1; test_case <= t; test_case++){

        int n;
        cin >> n;

        vector<int> arr(n);
        for(int& a : arr){
            cin >> a;
        }

        sort(arr.rbegin(), arr.rend());

        vector<long long> sum(n);
        vector<int> indices(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < arr[i]; j++){
                sum[i] += prime[j];
            }
        }

        int answer = -1;
 
        while(1){

            while(indices[0] + arr[0] < prime.size() and !is_prime[sum[0]]){
                sum[0] += prime[indices[0] + arr[0]] - prime[indices[0]];
                indices[0]++;
            }

            bool check = true;

            for(int i = 1; i < n; i++){

                while(indices[i] + arr[i] < prime.size() and sum[i] < sum[0]){
                    sum[i] += prime[indices[i] + arr[i]] - prime[indices[i]];
                    indices[i]++;
                }

                if(sum[i] != sum[0] or !is_prime[sum[i]]){
                    check = false;
                    break;
                }

            }

            if(check){
                answer = sum[0];
                break;
            }

            sum[0] += prime[indices[0] + arr[0]] - prime[indices[0]];
            indices[0]++;

        }

        cout << "Scenario " << test_case << ":\n";
        cout << answer << "\n\n";

    }

    return 0;
}