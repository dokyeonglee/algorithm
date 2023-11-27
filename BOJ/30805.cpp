#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];    
    }

    int m;
    cin >> m;

    vector<int> brr(m);
    for(int i = 0; i < m; i++){
        cin >> brr[i];    
    }

    vector<int> answer;

    int idx_a = 0;
    int idx_b = 0;

    for(int i = 100; i >= 1; i--){
        while(1){
            int j = idx_a;
            while(j < n){
                if(arr[j] == i){
                    break;
                }
                j++;
            }
            if(j == n){
                break;
            }
            int k = idx_b;
            while(k < m){
                if(brr[k] == i){
                    break;
                }
                k++;
            }
            if(k == m){
                break;
            }
            idx_a = j + 1;
            idx_b = k + 1;
            answer.push_back(i);
        }
    }

    cout << answer.size() << "\n";
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }

    return 0;
}