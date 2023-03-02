#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, l, a;
    cin >> n >> m >> l >> a;

    vector<pair<int, int>> arr(a);
    for(int i = 0; i < a; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    int answer = arr.size();

    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr.size(); j++){ 
            int result = arr.size();
            int x = arr[i].first;
            int y = arr[j].second;
            for(int k = 0; k < arr.size(); k++){
                if(x <= arr[k].first and arr[k].first <= x + l and y <= arr[k].second and arr[k].second <= y + l){
                    result--;
                }
            }
            answer = min(answer, result);
        }
    }

    cout << answer;

    return 0;
}