#include <iostream>
#include <vector>

using namespace std;

void push_topping(int row, int n){
    for(int i = 2; i <= n; i++){
        cout << "R " << row << " " << " push\n";
    }
}

void pull_topping(vector<string>& pizza, char dir, int row, int n){
    for(int i = 2; i <= n; i++){
        if(pizza[row - 1][i - 1] == '.'){
            cout << dir << " " << i << " " << " pull\n";
        }
    }
}



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> pizza(n);

    int r, c;
    cin >> r >> c;

    int cnt = n * n - 1;

    for(int i = 0; i < n; i++){
        cin >> pizza[i];
        for(int j = 0; j < n; j++){
            if(pizza[i][j] == '.'){
                cnt++;
            }
        }
    }

    cout << cnt << "\n";

    for(int i = 1; i < c; i++){
        cout << "L " << r << " push\n";
    }

    for(int i = c + 1; i <= n; i++){
        cout << "R " << r << " push\n";
    }

    for(int i = 1; i < r; i++){
        cout << "U 1 push\n";
    }

    for(int i = r + 1; i <= n; i++){
        cout << "D 1 push\n";
    }

    for(int i = r - 1; i >= 1; i--){
        push_topping(i, n);
        pull_topping(pizza, 'U', i, n);
    }

    pull_topping(pizza, 'D', r, n);

    for(int i = r + 1; i <= n; i++){
        push_topping(i, n);
        pull_topping(pizza, 'D', i, n);
    }
/*
    for(int i = r; i <= n; i++){
        if(i != r){
            for(int j = 2; j <= n; j++){
                cout << "R " << i << " " << " push\n";
            }
        }
        for(int j = 2; j <= n; j++){
            if(pizza[i - 1][j - 1] == '.'){
                cout << "D " << j << " " << " pull\n";
            }
        }
    }
*/
    for(int i = 1; i <= n; i++){
        if(pizza[i - 1][0] == '.'){
            cout << "L " << i << " " << " pull\n";
        }
    }


    return 0;
}