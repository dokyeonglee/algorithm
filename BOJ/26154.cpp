#include <iostream>
#include <vector>

using namespace std;

bool check(vector<vector<int>>& arr){
    bool result = (arr[0][1] == arr.size() * 2);
    for(int i = 1; i < arr.size(); i++){
        if(arr[i][0] >= arr.size()){
            result = false;
            break;
        }
    }
    return result;
}

void move(vector<vector<int>>& arr){
    int temp = arr[0][0];
    arr[0][0] = arr[0][1];
    for(int i = 1; i < arr.size(); i++){
        arr[i - 1][1] = arr[i][1];
        if(arr[i - 1][0] > arr[i - 1][1]){
            swap(arr[i - 1][0], arr[i - 1][1]);
        }
    }
    arr[arr.size() - 1][1] = temp;
    if(arr[arr.size() - 1][0] > arr[arr.size() - 1][1]){
        swap(arr[arr.size() - 1][0], arr[arr.size() - 1][1]);
    }
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> arr(n, vector<int>(2));

    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1];
        if(arr[i][0] > arr[i][1]){
            swap(arr[i][0], arr[i][1]);
        }
    }

    while(m > 0 and !check(arr)){
        m--;
        move(arr);
    }

    m %= n;

    if(m == 0){
        for(int i = 0; i < n; i++){
            cout << arr[i][0] << " " << arr[i][1] << "\n";
        }
    }else{
        cout << arr[m][1] << " " << arr[0][1] << "\n";
        for(int i = 1; i < n ;i++){
            cout << arr[i][0] << " ";
            if((i + m) % n == 0){
                cout << arr[0][0] << "\n";
            }else{
                cout << arr[(i + m) % n][1] << "\n";
            }
        }
    }

    return 0;
}