#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, p;
    cin >> n >> p;

    vector<int> arr(n);
    vector<int> brr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        cin >> brr[i];
    }

    int g1 = arr[0];
    for(int i = 1; i < n; i++){
        g1 = gcd(g1, arr[i]);
    }

    int g2 = brr[0];
    for(int i = 1; i < n; i++){
        g2 = gcd(g2, brr[i]);
    }

    int answer = 0;
    long long answer2 = 0;
    long long temp = 0;

    for(int i = 0; i < n; i++){
        arr[i] /= g1;
        brr[i] /= g2;
        answer += arr[i];
        if(brr[i]){
            temp = max(temp, (long long)(arr[i] + brr[i] - 1) / brr[i]);
        }
    }

    for(int i = 0; i < n; i++){
        answer2 += temp * brr[i];
    }

    cout << answer << " " << answer2;

    return 0;
}