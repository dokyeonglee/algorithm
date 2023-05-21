#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end());

    arr.push_back(make_pair(2123456789, 2123456789));

    int left = 0;
    int right = arr[0].second;

    vector<pair<int, int>> board;

    for(int i = 1; i <= n; i++){
        if(right < arr[i].first){
            board.push_back(make_pair(left, right));
            left = arr[i].first;
            right = arr[i].second;
        }else{
            right = max(right, arr[i].second);
        }
    }

    int answer = 0;
    int jump = 0;

    for(int i = 0; i < board.size(); i++){
        if(board[i].first > jump){
            break;
        }else{
            jump = max(jump, board[i].second + board[i].second - board[i].first);
        }
        answer = max(answer, board[i].second);
    }


    cout << answer;

    return 0;
}