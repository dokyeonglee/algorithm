#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        cout << (n + 1) / 2 << "\n";

        priority_queue<long long> left, right;

        vector<long long> answer;

        for(int i = 0; i < n; i++){

            int x;
            cin >> x;

            left.push(x);
            right.push(-left.top());
            left.pop();
            
            if(left.size() < right.size()){
                left.push(-right.top());
                right.pop();
            }

            if(i % 2 == 0){
                answer.push_back(left.top());
            }

        }

        for(int j = 0; j < answer.size(); j++){
            cout << answer[j] << " ";
            if(j % 10 == 9){
                cout << "\n";
            }
        }

        cout << "\n";
        
    }

    return 0;
}