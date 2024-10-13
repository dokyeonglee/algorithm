#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if(n == 1){
        cout << 1;
        return 0;
    }

    vector<vector<int>> arr(n);

    int p = 1;
    int x = 0;
    while(arr[p].size() < 2){
        arr[p].push_back(x++);
        p = p * 10 % n;
    }

    string answer((n - 1) * (arr[p][1] - arr[p][0]) + arr[p][0] + 1, '0');

    for(int i = 0; i < (n - 1) * (arr[p][1] - arr[p][0]); i += (arr[p][1] - arr[p][0])){
        answer[i] = '1';
    }

    answer[answer.size() - 1 - arr[p][0]] = '1';

    cout << answer;

    return 0;
}