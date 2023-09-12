#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

bool compare(long long a, long long b){
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    if(n < 4){
        cout << 2 * n - 1;
        return 0;
    }

    long long temp = n - 1;

    vector<long long> arr;

    for(long long i = 2; i * i <= n; i++){
        while(n % i == 0){
            arr.push_back(i);
            n /= i;
        }
    }

    if(n > 1){
        arr.push_back(n);
    }

    sort(arr.begin(), arr.end(), compare);

    string result1 = "";
    for(int i = 0; i < arr.size(); i++){
        result1 += to_string(arr[i]);
    }

    vector<long long> brr;

    while(temp > 3){
        brr.push_back(2);
        temp /= 2;
    }

    brr[0] = temp;
    brr.push_back(2);

    string result2 = "";
    for(int i = 0; i < brr.size(); i++){
        result2 += to_string(brr[i]);
    }

    if(result1.size() > result2.size()){
        result2 = string(result1.size() - result2.size(), '0') + result2;
    }else if(result1.size() < result2.size()){
        result1 = string(result2.size() - result1.size(), '0') + result1;
    }

    string answer = "";

    int carry = 0;

    for(int i = result1.size() - 1; i >= 0; i--){
        int a = result1[i] - '0';
        int b = result2[i] - '0';
        answer += '0' + (a + b + carry) % 10;
        carry = (a + b + carry) / 10;
    }

    if(carry == 1){
        answer += '1';
    }

    reverse(answer.begin(), answer.end());

    cout << answer;

    return 0;
}