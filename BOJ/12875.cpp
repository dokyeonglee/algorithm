#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b){
    return b ? gcd(b, a % b) : a;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int d;
    cin >> d;

    vector<vector<int>> arr(n, vector<int>(n, 987654321));

    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        arr[i][i] = 0;
        for(int j = 0; j < n; j++){
            if(str[j] == 'Y'){
                arr[i][j] = 1;
            }
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    int answer = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 987654321){
                cout << -1;
                return 0;
            }else{
                answer = max(answer, arr[i][j]);
            }
        }
    }

    cout << answer * d;

    return 0;
}