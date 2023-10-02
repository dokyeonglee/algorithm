#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if(n == 1){
        cout << "1.0000000000000";
        return 0;
    }

    vector<double> q(n + 1);
    vector<double> r(n + 1);

    double temp = 0;

    for(int i = 1; i <= n; i++){
        cin >> q[i];
    }

    for(int i = 1; i <= n; i++){
        cin >> r[i];
        r[i] += r[i - 1];
        temp += q[i] / (1 - r[i - 1]);
    }

    vector<double> answer(n + 1);
    
    for(int i = 1; i <= n; i++){
        answer[i] = q[i] / temp / (1 - r[i - 1]);
    }

    cout << fixed;
    cout.precision(10);

    for(int i = 1; i <= n; i++){
        cout << answer[i] << " ";
    }

    return 0;
}