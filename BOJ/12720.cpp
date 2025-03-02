#include <iostream>
#include <vector>

using namespace std;

int find_parent(vector<int>& parent, int x){
    if(parent[x] == x){
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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> is_prime(1e6, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i < 1000; i++){
        if(is_prime[i]){
            for(int j = i * i; j < 1000000; j += i){
                is_prime[j] = false;
            }
        }
    }

    vector<int> prime;

    prime.reserve(80000);

    for(int i = 2; i < 1e6; i++){
        if(is_prime[i]){
            prime.push_back(i);
        }
    }

    int c;
    cin >> c;

    vector<int> parent(1e6 + 1);

    for(int t = 1; t <= c; t++){

        int answer = 0;

        long long a, b, p;
        cin >> a >> b >> p;

        int n = b - a + 1;

        if(p >= 1e6){
            answer = n;
        }else{

            for(int i = 0; i < n; i++){
                parent[i] = i;
            }

            for(int i = 0; i < prime.size(); i++){
                if(prime[i] > b - a){
                    break;
                }
                if(prime[i] < p){
                    continue;
                }
                long long x = (a + prime[i] - 1) / prime[i] * prime[i];
                for(long long j = x + prime[i]; j <= b; j += prime[i]){
                    union_parent(parent, j - a, x - a);
                }
            }

            for(int i = 0; i < n; i++){
                if(find_parent(parent, i) == i){
                    answer++;
                }
            }

        }

        cout << "Case #" << t << ": " << answer << "\n";

    }

    return 0;

}