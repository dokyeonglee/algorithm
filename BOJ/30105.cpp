#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    map<int, int> mp;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        mp[arr[i]] = i;
    }

    if(n == 2){
        cout << "1\n";
        cout << arr[2] - arr[1];
    }else{

        vector<int> answer;

        for(int i = 2; i <= n / 2 + 1; i++){

            int k = arr[i] - arr[1];
            bool check = true;

            for(int j = 2; j <= n; j++){
                if(mp[arr[j] + k] == 0 and mp[arr[j] - k] == 0){
                    check = false;
                    break;
                }
            }

            if(check){
                answer.push_back(k);
            }

        }

        cout << answer.size() << "\n";
        for(int i = 0; i < answer.size(); i++){
            cout << answer[i] << " ";
        }

    }

    return 0;
}