#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> cnt(10001);
    vector<int> arr(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        cnt[arr[i]]++;
    }


    while(q--){
        int c, x;
        cin >> c >> x;
        if(c == 1){
            int answer = 0;
            if(n > 1){
                if(x == 0){
                    answer = (cnt[0] > 0);
                }else{
                    for(int i = 1; i * i <= x; i++){
                        if(cnt[i] and x % i == 0 and x / i <= 10000 and cnt[x / i]){
                            answer = 1;
                            if(i * i == x and cnt[i] == 1){
                                answer = 0;
                            }
                            break;
                        }
                    }
                }
            }
            cout << answer << "\n";
        }else{
            cnt[arr[x]]--;
            arr[x] = 0;
            cnt[0]++;
        }
    }

    return 0;
}