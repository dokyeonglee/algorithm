#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        int a, b, c;
        cin >> a >> b >> c;

        int ab, bc, ca;
        cin >> ab >> bc >> ca;

        int answer = 0;

        for(int i = 0; i <= min(a, b); i++){
            int result = i * ab;
            a -= i;
            b -= i;
            int amount_bc = 0;
            if(bc > ca){
                amount_bc = min(b, c);
            }else{
                amount_bc = min(b, c - min(a, c));
            }
            result += amount_bc * bc;
            result += min(a, c - amount_bc) * ca;
            answer = max(answer, result);
            a += i;
            b += i;
        }

        cout << answer << "\n";
    }

    return 0;
}