#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<int> arr(n + 1);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> cnt(100001); 
    cnt[arr[0]] = 1;

    int left = 0;
    int right = 0;
    int number_of_unique = 1;

    long long answer = 0;

    while(right < n){
        if(number_of_unique == right - left + 1){
            answer += number_of_unique;
            if(cnt[arr[++right]]++ == 0){
                number_of_unique++;
            }else{
                number_of_unique--;
            }
        }else{
            if(--cnt[arr[left++]] == 1){
                number_of_unique++;
            }else{
                number_of_unique--;
            }
        }
    }

    cout << answer;

    return 0;
}