#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    cin >> n >> l;

    vector<int> lengths(n);
    vector<int> directions(n);
    vector<int> pos(n);

    for(int idx = 0; idx < n; idx++){
        cin >> lengths[idx] >> directions[idx];
        if(directions[idx]){
            pos[idx] = l - lengths[idx];
        }
    }

    int idx = 0;
    int answer = 0;

    for(int idx = 0; idx + 1 < n; idx++){
        while(!(pos[idx] >= pos[idx + 1] and pos[idx] <= pos[idx + 1] + lengths[idx + 1] or pos[idx] + lengths[idx] >= pos[idx + 1] and pos[idx] + lengths[idx] <= pos[idx + 1] + lengths[idx + 1])
        and !(pos[idx + 1] >= pos[idx] and pos[idx + 1] <= pos[idx] + lengths[idx] or pos[idx + 1] + lengths[idx + 1] >= pos[idx] and pos[idx + 1] + lengths[idx + 1] <= pos[idx] + lengths[idx])){
            answer++;
            for(int i = idx; i < n; i++){
                if(directions[i] == 0){
                    pos[i]++;
                    if(pos[i] + lengths[i] == l){
                        directions[i] = 1;
                    }
                }else{
                    if(--pos[i] == 0){
                        directions[i] = 0;
                    }
                }
            }
        }
    }

    cout << answer;

    return 0;
}