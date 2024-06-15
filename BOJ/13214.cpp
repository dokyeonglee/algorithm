#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> brr(n);

    for(auto& a : arr){
        cin >> a;
    }

    for(auto& b : brr){
        cin >> b;
    }

    vector<bool> visited(n);

    vector<int> pos(n + 1);

    for(int i = 0; i < n; i++){
        pos[brr[i]] = i;
    }

    int answer = 0;

    for(int i = 0; i < n; i++){
        if(visited[i] or pos[arr[i]] == i){
            continue;
        }
        int cnt = 0;
        int temp = i;
        while(!visited[temp]){
            visited[temp] = true;
            temp = pos[arr[temp]];
            cnt++;
        }
        answer += cnt - 1;
    }

    cout << answer;

    return 0;
}