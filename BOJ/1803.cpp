#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n + m);
    vector<int> in_degree(n + m);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i] += n - 1;
    }

    for(int i = 0; i < m; i++){
        cin >> arr[n + i];
        arr[n + i]--;
        in_degree[arr[n + i]]++;
    }

    queue<int> q;

    vector<int> answer(n + m);

    for(int i = 0; i < m; i++){
        answer[n + i] = 1;
    }

    for(int i = 0; i < n; i++){
        if(in_degree[i] == 0){
            answer[i] = 1;
            q.push(i);
        }        
    }

    while(!q.empty()){
        int bow = q.front();
        q.pop();
        int shield = arr[bow];
        if(answer[shield] == 1){
            answer[shield] = 0;
            if(--in_degree[arr[shield]] == 0){
                answer[arr[shield]] = 1;
                q.push(arr[shield]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << answer[i];
    }
    cout << "\n";
    for(int i = 0; i < m; i++){
        cout << answer[n + i];
    }

    return 0;
}