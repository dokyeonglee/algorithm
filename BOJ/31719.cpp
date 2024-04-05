#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void open_stack(vector<int>& top, vector<int>& bottom, int& now){

    for(int k = 0; k < 2; k++){
        for(int j = 0; j < 2; j++){
            if(bottom[j] == now){
                now = top[j] + 1;
                top[j] = -1;
                bottom[j] = -1;
            }
        }
    }

}

bool can_push(vector<int>& top, vector<int>& bottom, int a){

    for(int i = 0; i < 2; i++){
        if(top[i] + 1 == a){
            top[i] = a;
            return true;
        }
    }

    for(int i = 0; i < 2; i++){
        if(top[i] == -1){
            top[i] = a;
            bottom[i] = a;
            return true;
        }
    }   

    return false;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int now = 1;

        vector<int> top(2, -1);
        vector<int> bottom(2, -1);

        vector<int> arr(n);

        for(auto& a : arr){
            cin >> a;
        }

        bool check = true;

        for(auto& a : arr){

            open_stack(top, bottom, now);

            if(now == a){
                now++;
            }else if(!can_push(top, bottom, a)){
                check = false;
                break;
            }

        }

        if(check){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
        
    }

    return 0;
}