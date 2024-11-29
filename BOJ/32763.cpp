#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<bool> same_sign_with_first_element(n + 1);
    same_sign_with_first_element[1] = true;

    char op;

    for(int i = 1; i < n; i++){
        cout << "? 1 * " << i + 1 << endl;
        cin >> op;
        same_sign_with_first_element[i + 1] = (op == '+');
    }

    int b;
    int a = 1;
    bool is_first_element_positive = false;

    if(same_sign_with_first_element[2]){
        b = 2;
    }else if(same_sign_with_first_element[3]){
        b = 3;
    }else{
        a = 2;
        b = 3;
        is_first_element_positive = true;
    }

    cout << "? " << a << " + " << b << endl;
    cin >> op;

    is_first_element_positive ^= (op == '+');

    char sign_of_first_element;
    char sign_of_other_element;

    if(is_first_element_positive){
        sign_of_first_element = '+';
        sign_of_other_element = '-';
    }else{
        sign_of_first_element = '-';
        sign_of_other_element = '+';
    }

    cout << "! ";

    for(int i = 1; i <= n; i++){
        if(same_sign_with_first_element[i]){
            cout << sign_of_first_element << " ";
        }else{
            cout << sign_of_other_element << " ";
        }
    }


    return 0;
}