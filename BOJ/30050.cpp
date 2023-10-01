#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    map<int, int> parent;

    while(t--){

        int c, a, b;
        cin >> c >> a >> b;

        if(c == 1){
            parent[b] = a;
        }else{

            long long answer = 0;

            while(a != b){
                if(a > b){
                    answer += a;
                    if(parent.count(a)){
                        a = parent[a];
                    }else{
                        a /= 2;
                    }
                }else{
                    answer += b;
                    if(parent.count(b)){
                        b = parent[b];
                    }else{
                        b /= 2;
                    }
                }
            }

            answer += a;

            cout << answer << "\n";
        }   
    }

    return 0;
}