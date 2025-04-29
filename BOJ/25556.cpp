#include <iostream>
#include <vector>
//#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> s(4);

    int n;
    cin >> n;

    while(n--){
        int x;
        cin >> x;
        int idx = -1;
        int a = -1;
        for(int i = 0; i < 4; i++){
            if(s[i] < x){
                if(a < s[i]){
                    a = s[i];
                    idx = i;
                }
            }
        }
        if(idx == -1){
            cout << "NO";
            return 0;
        }
        s[idx] = x;
    }

    cout << "YES";

    return 0;

}