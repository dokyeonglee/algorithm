#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long bellman_ford(vector<pair<int, pair<int, int>>>& edges, int number_of_city, int src, int money){

    vector<long long> distance(number_of_city + 1, 1e18);
    distance[src] = -money;

    for(int i = 1; i < number_of_city; i++){
        for(auto& e : edges){
            int u = e.second.first;
            int v = e.second.second;
            int c = e.first;
            if(distance[u] != 1e18){
                distance[v] = min(distance[v], distance[u] + c - money);
            }
        }
    }

    for(auto& e : edges){
        int u = e.second.first;
        int v = e.second.second;
        int c = e.first;
        if(distance[v] > distance[u] + c - money){
            return -1;
        }
    }

    return -*min_element(distance.begin() + 1, distance.end());

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int money, p, number_of_city, f, src;
    cin >> money >> p >> number_of_city >> f >> src;

    vector<pair<int, pair<int, int>>> edges(p + f);

    for(int i = 0; i < p; i++){
        cin >> edges[i].second.first >> edges[i].second.second;
    }

    for(int i = p; i < p + f; i++){
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    }

    cout << bellman_ford(edges, number_of_city, src, money);


    return 0;
}