#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int number_of_nodes, number_of_edges;
    cin >> number_of_nodes >> number_of_edges;

    vector<int> out_degree(number_of_nodes + 1);
    for (int i = 0; i < number_of_edges; ++i) {
        int from, to;
        cin >> from >> to;
        out_degree[from]++;
    }

    cout << count(out_degree.begin(), out_degree.end(), 1) << '\n';

    return 0;

}