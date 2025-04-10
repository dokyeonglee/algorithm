#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<string>& arr){
    vector<string> temp(arr[0].size());
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[0].size(); j++){
            temp[j].push_back(arr[arr.size() - 1 - i][j]);
        }
    }
    arr = temp;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n1, m1;
    cin >> n1 >> m1;

    vector<string> arr(n1);
    for(auto& a : arr){
        cin >> a;
    }

    int n2, m2;
    cin >> n2 >> m2;

    vector<string> arr2(n2);
    for(auto& a : arr2){
        cin >> a;
    }

    int answer = 1e9;

    for(int i = 0; i < 4; i++){
        answer = min(answer, min((n1 + n2) * max(m1, m2), (m1 + m2) * max(n1, n2)));
        for(int dr = -n2 + 1; dr < n1; dr++){
            for(int dc = -m2 + 1; dc < m1; dc++){
                bool check = true;
                for(int r = 0; r < n2; r++){
                    for(int c = 0; c < m2; c++){
                        if(arr2[r][c] == '1'){
                            if(r + dr >= 0 and r + dr < n1 and c + dc >= 0 and c + dc < m1 and arr[r + dr][c + dc] == '1'){
                                check = false;
                                break;
                            }
                        }
                    }
                    if(!check){
                        break;
                    }
                }
                if(check){
                    answer = min(answer, (max(n1, n2 + dr) - min(0, dr)) * (max(m1, m2 + dc) - min(0, dc)));
                }
            }
        }
        rotate(arr2);
        swap(n2, m2);
    }

    cout << answer;

    return 0;

}