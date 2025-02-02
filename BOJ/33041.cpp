#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h;
    cin >> h;

    vector<int> arr(h + 1);
    for(int i = 0; i < h; i++){
        cin >> arr[i];
    }

    int c, d;
    cin >> c >> d;

    vector<int> cnt(h + 1);

    cnt.back() = 1e8;

    for(int i = 1; i < h; i++){
        while(d > 0 and cnt[i] < arr[i] and arr[i - 1] + 8 * cnt[i - 1] >= arr[i] + 8 * cnt[i]){
            cnt[i]++;
            d--;
        }
        if(arr[i - 1] + 8 * cnt[i - 1] >= arr[i] + 8 * cnt[i]){
            cout << -1;
            return 0;
        }
    }

    for(int i = h - 1; i >= 0; i--){
        while(d > 0 and cnt[i] < arr[i] and arr[i] + 8 * cnt[i] + 8 < arr[i + 1] + 8 * cnt[i + 1]){
            cnt[i]++;
            d--;
        }
    }

    if(d > 0){
        cout << -1;
        return 0;
    }

    for(int i = 0; i < h; i++){
        for(int j = cnt[i]; j < arr[i]; j++){
            cout << "1 ";
        }
        for(int j = 0; j < cnt[i]; j++){
            cout << "9 ";
        }
        cout << "\n";
    }

    return 0;

}