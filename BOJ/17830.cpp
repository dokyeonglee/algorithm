#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        string str;
        cin >> str;

        int max_number_of_digit = -1;
        int min_number_of_digit = -1;

        int idx = 0;
        int idx2 = 0;

        while(idx < n and str[idx] == '0'){
            idx++;
        }

        if(idx == n){
            max_number_of_digit = 1;
            min_number_of_digit = 1;
        }else{

            idx2 = idx + 1;
            while(idx2 < n and str[idx2] == '0'){
                idx2++;
            }

            max_number_of_digit = 2 * n - idx;

            if(idx2 == n){

                max_number_of_digit--;

                if(str[idx] == '1'){
                    min_number_of_digit = 2 * n - idx - 1;
                }else{
                    min_number_of_digit = 1;
                }

            }else{

                while(idx < n and str[idx] != '1'){
                    idx++;
                }

                if(idx == n){
                    min_number_of_digit = 1;
                }else{

                    min_number_of_digit = 2 * n - idx;

                    idx2 = idx + 1;
                    while(idx2 < n and str[idx2] != '1'){
                        idx2++;
                    }

                    if(idx2 == n){
                        min_number_of_digit--;
                    }

                }
            }
        }

        cout << max_number_of_digit << " " << min_number_of_digit << "\n";

    }

    return 0;

}