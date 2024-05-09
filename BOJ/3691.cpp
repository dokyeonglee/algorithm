#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        int a, b;
        cin >> a >> b;

        map<string, map<string, pair<int, int>>> mp;

        for(int i = 0; i < a; i++){
            string type, name;
            int price, quality;
            cin >> type >> name >> price >> quality;
            mp[type][name] = make_pair(price, quality);
        }

        int left = 0;
        int right = 1e9;
        int answer = 0;

        while(left <= right){
            int mid = (left + right) / 2;
            long long sum = 0;
            for(auto& it : mp){
                int temp = 1e9 + 1;
                for(auto& i : it.second){
                    if(mid <= i.second.second){
                        temp = min(temp, i.second.first);
                    }
                }
                if(temp == 1e9 + 1){
                    sum = 1e9 + 1;
                    break;
                }else{
                    sum += temp;
                }
            }
            if(sum <= b){
                answer = mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        cout << answer << "\n";

    }

    return 0;
}