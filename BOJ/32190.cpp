#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    deque<int> answer;

    if(n % 2){
        answer.push_front(1);
        answer.push_back(1);
    }

    for(int i = 2 + n % 2; i <= n; i += 2){
        answer.push_front(i);
        answer.push_back(i - 1);
        answer.push_back(i);
        answer.push_back(i - 1);
    }

    for(auto& x : answer){
        cout << x << " ";
    }

    return 0;
}