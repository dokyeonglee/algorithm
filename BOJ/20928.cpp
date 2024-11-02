#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int answer = 0;

    int n, m;
    cin >> n >> m;

    vector<int> p(n);
    vector<int> x(n);

    for(int i = 0; i < n; i++){
        cin >> p[i];    
    }

    for(int i = 0; i < n; i++){
        cin >> x[i];
    }

    int reach = p[0] + x[0];
    int transfer_idx = 0;

    while(transfer_idx < n){
        if(reach < m){
            int next_reach = reach;
            while(transfer_idx < n and p[transfer_idx] <= reach){
                next_reach = max(next_reach, p[transfer_idx] + x[transfer_idx]);
                transfer_idx++;
            }
            if(reach == next_reach){
                break;
            }
            reach = next_reach;
            answer++;
        }else{
            cout << answer;
            return 0;
        }
    }

    if(reach < m){
        cout << -1;
    }else{
        cout << answer;
    }

    return 0;
}