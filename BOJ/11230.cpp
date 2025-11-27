#include <iostream>

using namespace std;

int main() {    
    int n;
    cin >> n;

    string answer = "a";
    if (n <= 25) {
        answer += 'a' + n;
    } else {
        while (n > 0) {
            int diff = min(n, 25);
            if (answer.back() == 'a') {
                answer += 'a' + diff;
            } else if (answer.back() == 'z') {
                answer += 'z' - diff;
            }
            n -= diff;
        }
        if (answer.size() % 2 == 0) {
            int temp = ('z' - answer.back()) / 2;
            answer[1] -= temp;
            answer.back() += 2 * temp;
        } else {
            int temp = (answer.back() - 'a') / 2;
            answer[1] -= temp;
            answer.back() -= 2 * temp;
        }
    }

    cout << answer;

    return 0;
}