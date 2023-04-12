#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    vector<long long> arr(100005);

    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        for(int i = 0; i < k; i++){
            int s, e;
            cin >> s >> e;
            arr[s + 1]++;
            arr[e + 1]--;
        }
    }
    
    for(int i = 2; i <= 100000; i++){
        arr[i] += 2 * arr[i - 1] - arr[i - 2];
    }

    pair<int, int> answer;
    long long sum = 0;

    for(int i = 0; i <= 100000 - t + 1; i++){
        if(arr[i + t] - arr[i] > sum){
            sum = arr[i + t] - arr[i];
            answer = make_pair(i, i + t);
        }
    }

    cout << answer.first << " " << answer.second;

    return 0;
}