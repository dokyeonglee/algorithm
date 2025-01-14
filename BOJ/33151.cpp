#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    if(n == 1){
        cout << k;
        return 0;
    }


    if((k % 2 == 1 and n % 2 == 0) or k < n * n / 2){
        cout << -1;
    }else{

        int r = k % 2;

        int x = r;
        int y = 1 - x;

        if(r == 0){
            k -= n * n / 2;
        }else{
            k -= (n * n + 1) / 2;
        }

        int temp = k / (n * n) / 2 * 2;

        k -= n * n * temp;

        x += temp;
        y += temp;

        bool add_to_y = false;

        if(r == 0){
            if(k >= (n * n + 1) / 2 * 2){
                x += 2;
                k -= (n * n + 1) / 2 * 2;
                add_to_y = true;
            }
        }else{
            if(k >= n * n / 2 * 2){
                y += 2;
                k -= n * n / 2 * 2;
            }else{
                add_to_y = true;
            }
        }

        if(k > 0){
            if(!add_to_y){
                x += 2;
            }else{
                y += 2;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if((i + j) % 2 == 0){
                    cout << x << " ";
                }else{
                    cout << y << " ";
                }
                if(--k == 0){
                    if(!add_to_y){
                        x -= 2;
                    }else{
                        y -= 2;
                    }
                }
            }
            cout << "\n";
        }
    }

    return 0;

}