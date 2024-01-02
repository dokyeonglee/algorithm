#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> or_less(n + 1);
    vector<int> or_more(n + 1);

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x > 0){
            or_more[x]++;
        }else{
            or_less[-x]++;
        }
    }

    for(int i = n; i >= 1; i--){
        or_more[i - 1] += or_more[i];
    }

    for(int i = 1; i <= n; i++){
        or_less[i] += or_less[i - 1];
    }

    vector<int> answer;

    if(or_more[1] == 0){
        answer.push_back(0);
    }

    for(int i = 1; i < n; i++){
        if(or_more[i + 1] + or_less[i - 1] == i){
            answer.push_back(i);
        }
    }

    if(or_less[n - 1] == n){
        answer.push_back(n);
    }

    cout << answer.size() << "\n";
    for(int& a : answer){
        cout << a << " ";
    }

    return 0;
}