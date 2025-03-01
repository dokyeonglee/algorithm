#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        string result = to_string(100 + i);
        while(x--){
            result += '0';
        }
        cout << result << " ";
    }

    return 0;

}