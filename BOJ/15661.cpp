#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> sum(n);

    int total = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            sum[i] += x;
            sum[j] += x;
            total += x;
        }
    }

    int sz = (1 << n) - 1;

    int answer = 1e9;

    for(int i = 1; i < sz; i++){
        if(__builtin_popcount(i) > n / 2){
            continue;
        }
        int temp = 0;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){   
                temp += sum[j];
            }
        }
        answer = min(answer, abs(total - temp));
        if(answer == 0){
            break;
        }
    }

    cout << answer;

    return 0;

}