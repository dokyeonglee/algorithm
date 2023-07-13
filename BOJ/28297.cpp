#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double pi = 3.1415926535;

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

    int n;
    cin >> n;

    vector<int> parent(n + 1);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    vector<pair<int, pair<int, int>>> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i].second.first >> arr[i].second.second >> arr[i].first;
    }

    vector<pair<double, pair<int, int>>> edges;

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            double d = 0.0;
            int x = (arr[i].second.first - arr[j].second.first) * (arr[i].second.first - arr[j].second.first) 
                        + (arr[i].second.second - arr[j].second.second) * (arr[i].second.second - arr[j].second.second);
            if(arr[i].second == arr[j].second or x <= (arr[i].first + arr[j].first) * (arr[i].first + arr[j].first)){

            }else{
                double h = sqrt(x - (arr[i].first - arr[j].first) * (arr[i].first - arr[j].first));
                double theta = acos((arr[i].first - arr[j].first) / (double)sqrt(x));
                d += 2 * h;
                d += arr[i].first * 2 * (pi - theta);
                d += arr[j].first * 2 * theta;
            }
            edges.push_back(make_pair(d, make_pair(i, j)));
        }
    }

    sort(edges.begin(), edges.end());

    double answer = 0;

    for(auto edge : edges){
        double d = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find_parent(parent, u) != find_parent(parent, v)){
            answer += d;
            union_parent(parent, u, v);
        }
    }

    cout.precision(10);
    cout << answer;

    return 0;
}