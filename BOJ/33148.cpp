#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> arr(n * n);
    map<long long, int> mp;

    for(auto& a : arr){
        cin >> a;
    }

    sort(arr.begin(), arr.end());

    vector<long long> answer;

    const long long a = sqrtl(arr[0]);

    if(a * a != arr[0]){
        cout << "NO";
        return 0;
    }

    int idx = 0;

    while(idx < arr.size()){
        if(mp[arr[idx]]--){
            idx++;
            continue;
        }
        long long x = arr[idx] / a;
        if(x > 1e9){
            cout << "NO";
            return 0;
        }
        answer.push_back(x);
        for(int i = 0; i < answer.size(); i++){
            mp[x * answer[i]] += 2;
        }
        mp[x * x]--;
        idx++;
    }

    if(answer.size() != n){
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    for(auto& a : answer){
        cout << a << " ";
    }

    return 0;

}