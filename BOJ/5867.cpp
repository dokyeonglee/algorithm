#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> arr(n);
    vector<string> brr(n);

    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        arr[i] = str;
        brr[i] = str;
    }

    vector<string> sorted_str(n);
    vector<string> reverse_sorted_str(n);

    for(int i = 0; i < n; i++){
        sort(arr[i].begin(), arr[i].end());
        sorted_str[i] = arr[i];
    }

    for(int i = 0; i < n; i++){
        sort(brr[i].rbegin(), brr[i].rend());
        reverse_sorted_str[i] = brr[i];
    }

    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());

    for(int i = 0; i < n; i++){
        cout << lower_bound(brr.begin(), brr.end(), sorted_str[i]) - brr.begin() + 1 << " " << upper_bound(arr.begin(), arr.end(), reverse_sorted_str[i]) - arr.begin() << "\n";
    }

    return 0;
}