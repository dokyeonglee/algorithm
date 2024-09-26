#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int geunseong = 0;

    vector<int> garbage;

    garbage.push_back(0);

    int n;
    cin >> n;

    long long answer = 0;

    while(n--){
        int x;
        cin >> x;
        if(x == 1){
            int y;
            cin >> y;
            garbage.push_back(y);
        }else{
            sort(garbage.begin(), garbage.end());
            int left = lower_bound(garbage.begin(), garbage.end(), geunseong) - garbage.begin() - 1;
            int right = left + 2;
            while(left >= 0 or right < garbage.size()){
                if(left == -1){
                    answer += garbage[right] - geunseong;
                    geunseong = garbage[right++];
                }else if(right == garbage.size()){
                    answer += geunseong - garbage[left];
                    geunseong = garbage[left--];
                }else{
                    if(geunseong - garbage[left] <= garbage[right] - geunseong){
                        answer += geunseong - garbage[left];
                        geunseong = garbage[left--];
                    }else{
                        answer += garbage[right] - geunseong;
                        geunseong = garbage[right++];
                    }
                }
            }
            garbage.clear();
            garbage.push_back(geunseong);
        }
    }

    cout << answer;


    return 0;
}