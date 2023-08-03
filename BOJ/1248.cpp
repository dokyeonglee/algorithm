#include <iostream>
#include <vector>

using namespace std;

bool possible(string& str, vector<int>& arr, int idx){
    int x = idx - 1;
    for(int i = 1; i <= idx; i++){
        int s = arr[idx] - arr[i - 1];
        if((str[x] == '0' and s != 0) or (str[x] == '+' and s <= 0) or (str[x] == '-' and s >= 0)){
            return false;
        }
        x += arr.size() - i - 1;
    }
    return true;
}

void dfs(string& str, vector<int>& arr, int idx, int x){

    if(idx == arr.size()){
        for(int i = 1; i < arr.size(); i++){
            cout << arr[i] - arr[i - 1] << " ";
        }
        exit(0);
    }

    int s = 0;
    int e = 0;

    if(str[x] == '+'){
        s = 1;
        e = 10;
    }else if(str[x] == '-'){
        s = -10;
        e = -1;
    }

    for(int i = s; i <= e; i++){
        arr[idx] = arr[idx - 1] + i;
        if(possible(str, arr, idx)){
            dfs(str, arr, idx + 1, x + arr.size() - idx);
        }
    }

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string str;
    cin >> str;

    vector<int> arr(n + 1);
    
    dfs(str, arr, 1, 0);

    return 0;
}