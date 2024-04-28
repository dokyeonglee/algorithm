#include <iostream>
#include <vector>
#include <map>

using namespace std;

int max_number_of_pack(vector<int>& cards, int x){

    int result = 0;
    int idx = 0;

    while(idx + x <= cards.size()){
        map<int, int> temp;
        int cnt = 0;
        for(int i = 0; i < x; i++){
            if(temp.count(cards[idx + i]) == 0){
                cnt++;
                temp[cards[idx + i]] = idx + i;
            }else{
                idx = temp[cards[idx + i]] + 1;
                break;
            }
        }
        if(cnt == x){
            result++;
            idx += x;
        }
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> cards(n);

    for(int& card : cards){
        cin >> card;
    }

    int left = 1;
    int right = n;

    int answer = 1;

    while(left <= right){
        int mid = (left + right) / 2;
        int cnt = max_number_of_pack(cards, mid);
        if(cnt >= m){
            left = mid + 1;
            answer = mid;
        }else{
            right = mid - 1;
        }
    }

    cout << answer;

    return 0;
}