#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string str;
    cin >> str;

    int answer = 0;

    vector<int> v;

    for(int i = 0; i < n; i++){
        if(str[i] == 's'){
            v.push_back(0);
        }else if(str[i] == 'k'){
            if(!v.empty() and v.back() == 0){
                v.back()++;
            }else{
                v.clear();
            }
        }else if(str[i] == 'e'){
            if(!v.empty()){
                if(v.back() == 1 or v.back() == 2){
                    v.back()++;
                }else{
                    v.clear();
                }
            }
        }else if(str[i] == 'p'){
            if(!v.empty() and v.back() == 3){
                v.back()++;
                while(!v.empty() and v.back() == 4){
                    answer++;
                    v.pop_back();
                    if(!v.empty()){
                        v.back()++;
                    }
                }
            }else{
                v.clear();
            }
        }else{
            v.clear();
        }
    }

    cout << answer;

    return 0;

}