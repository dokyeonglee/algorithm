#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    priority_queue<int> pq;

    if(m > 7){
        cout << -1;
        return 0;
    }

    int temp = n;

    vector<int> arr;

    for(int i = 2; i * i <= temp; i++){
        int p = 1;
        while(temp % i == 0){
            p *= i;
            temp /= i;
        }
        if(p > 1){
            arr.push_back(p);
        }
    }

    if(temp > 1){
        arr.push_back(temp);
    }

    if(arr.size() < m){
        cout << -1;
        return 0;
    }

    int s = 1;
    int min_sum_of_salary = 1e9;

    for(int i = 1; i < arr.size(); i++){
        s *= m;
    }

    int _answer = -1;
    vector<int> answer(m, n);

    answer[0] /= arr[0];

    for(int i = 0; i < s; i++){

        temp = i;

        vector<int> player(m, 1);

        player[0] = arr[0];

        for(int j = 1; j < arr.size(); j++){
            player[temp % m] *= arr[j];
            temp /= m;
        }

        int sum_of_salary = 0;
        bool check = false;

        for(int j = 0; j < m; j++){
            if(player[j] == 1){
                check = true;
                break;
            }
            sum_of_salary += n / player[j];
        }

        if(check){
            continue;
        }

        if(sum_of_salary < min_sum_of_salary){
            _answer = i;
            min_sum_of_salary = sum_of_salary;
        }
    }

    for(int j = 1; j < arr.size(); j++){
        answer[_answer % m] /= arr[j];
        _answer /= m;
    }

    for(auto& x : answer){
        cout << x << " ";
    }

    return 0;
}