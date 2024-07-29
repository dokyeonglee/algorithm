#include <iostream>
#include <vector>

using namespace std;
//중복이 있는 배열에서 가장 작은 두 개의 원소
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> x(n);
    vector<int> y(n);
    vector<int> z(n);

    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> z[i];
    }

    int answer = 1e9;

    for(int i = 0; i < n; i++){
        int first = 1e9;
        int second = 1e9;
        for(int j = 0; j < n; j++){
            if(i == j){
                continue;
            }
            int d = abs(x[i] - x[j]) + abs(y[i] - y[j]) + abs(z[i] - z[j]);
            if(d < first){
                second = first;
                first = d;
            }else if(d < second){
                second = d;
            }
        }
        answer = min(answer, first + second);
    }

    cout << answer;

    return 0;
}