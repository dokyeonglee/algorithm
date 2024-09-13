#include <iostream>
#include <vector>

using namespace std;

bool possible(vector<int>& average, int n){

    for(int& a : average){

        int left = 0;
        int right = 10 * n;
        bool check = false;

        while(left <= right){
            int mid = (left + right) / 2;
            int temp = mid * 1000 / n;
            if(temp == a){
                check = true;
                break;
            }else if(temp < a){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        if(!check){
            return false;
        }

    }

    return true;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> average(n);

    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        average[i] = stoi(str.substr(0, str.size() - 4)) * 1000 + stoi(str.substr(str.size() - 3));
    }

    for(int i = 1; i <= 1000; i++){
        if(possible(average, i)){
            cout << i;
            return 0;
        }        
    }

    return 0;
}