#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, k;
    cin >> n >> k;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<int> d(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }

    vector<bool> check(n + 1);
    vector<int> answer(n + 1);
    vector<int> indices(n + 1);

    for(int i = 1; i <= n; i++){
        if(!check[i]){
            int cnt = 0;
            int now = i;
            while(!check[now]){
                check[now] = true;
                indices[cnt++] = now;
                now = d[now];
            }
            for(int j = 0; j < cnt; j++){
                answer[indices[(j + k) % cnt]] = arr[indices[j]];
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << answer[i] << " ";
    }

    return 0;
}