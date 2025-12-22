#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int find_parent(vector<int>& parent, int x){
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    parent[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll a, b, p;
    cin >> a >> b >> p;

    vector<bool> is_prime(b - a + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i < is_prime.size(); ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < is_prime.size(); j += i) {
                is_prime[j] = false;
            }
        }
    }

    vector<int> parent(b - a + 1);
    for (int i = 0; i < parent.size(); ++i) {
        parent[i] = i;
    }

    for (int i = p; i < is_prime.size(); ++i) {
        if (is_prime[i]) {
            ll temp = a + (i - a % i) % i;
            for (ll j = temp + i; j <= b; j += i) {
                union_parent(parent, temp - a, j - a);
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < parent.size(); ++i) {
        if (find_parent(parent, i) == i) {
            ++answer;
        }
    }

    cout << answer << '\n';

    return 0;
}