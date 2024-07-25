#include <iostream>
#include <vector>

using namespace std;

/*

1) n=1
A가 진다.

2) n>=2
처음에 A가 1을 골랐다 가정하자.
B가 무슨 수를 골라도 이길 수 없다면 A는 그대로 1을 고르면 이길 수 있다.
B가 이길 수 있는 어떤 수가 존재하고 이 수를 X라 하면, A는 1이 아닌 X를 고르면 이길 수 있다

*/

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if(n == 1){
        cout << "B";
    }else{
        cout << "A";
    }

    return 0;
}