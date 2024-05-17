#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    string str;
    cin >> str;

    int left = 0;
    int right = n - 1;

    vector<int> p;
    vector<int> c;

    while(left < right and k){
        while(left < right and str[left] == 'P'){
            left++;
        }
        while(left < right and str[right] == 'C'){
            right--;
        }
        if(left < right){
            if(str[left] == 'C' and str[right] == 'P'){
                swap(str[left], str[right]);
                left++;
                right--;
                k--;
            }
        }
    }

    long long answer = 0;

    long long cnt = 0;

    for(int i = 0; i < n; i++){
        if(str[i] == 'C'){
            answer += cnt * (cnt - 1) / 2;
        }else{
            cnt++;
        }
    }

    cout << answer;

    return 0;
}