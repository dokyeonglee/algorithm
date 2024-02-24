#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> x(n);
    vector<long long> p(n);

    for(int i = 0; i < n; i++){
        cin >> x[i] >> p[i];
    }

    long long sum = 0;

    int idx = -1;
    int max_p = 0;

    for(int i = 0; i < n; i++){
        if(sum <= x[i]){
            sum += p[i];
        }else{
            idx = i;
            break;
        }
        if(max_p < p[i]){
            max_p = p[i];
        }
    }

    if(idx == -1){
        cout << "Kkeo-eok";
    }else{
        long long temp = sum;
        bool check = true;
        for(int i = idx + 1; i < n; i++){
            if(sum <= x[i]){
                sum += p[i];
            }else{
                check = false;
                break;
            }
        }
        if(check){
            cout << "Kkeo-eok";
        }else{
            sum = temp - max_p;
            for(int i = idx; i < n; i++){
                if(sum <= x[i]){
                    sum += p[i];
                }else{
                    cout << "Zzz";
                    return 0;
                }
            }
            cout << "Kkeo-eok";
        }
    }

    return 0;
}