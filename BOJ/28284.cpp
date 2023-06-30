#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<long long> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    sort(arr.begin() + 1, arr.end());

    for(int i = 1; i <= n; i++){
        arr[i] += arr[i - 1];
    }

    vector<pair<int, int>> customer(2 * m);
    for(int i = 0; i < 2 * m; i += 2){
        int s, e;
        cin >> s >> e;
        customer[i] = make_pair(s, 1);
        customer[i + 1] = make_pair(e + 1, -1);
    }

    sort(customer.begin(), customer.end());

    long long answer = 0;
    long long answer2 = 0;
    int s = customer[0].first;
    int cnt = 0;

    for(int i = 0; i < customer.size(); i++){
        answer += (customer[i].first - s) * arr[cnt];
        answer2 += (customer[i].first - s) * (arr[n] - arr[n - cnt]);
        if(customer[i].second == 1){
            cnt++;
        }else{
            cnt--;
        }
        s = customer[i].first;
    }

    cout << answer << " " << answer2;

    return 0;
}