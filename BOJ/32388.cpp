    #include <iostream>
    #include <vector>
    #include <cmath>

    using namespace std;

    double get_distance(pair<int, int>& a, pair<int, int>& b){
        return sqrtl(1ll * (a.first - b.first) * (a.first - b.first) + 1ll * (a.second - b.second) * (a.second - b.second));
    }

    double dijkstra(vector<vector<double>>& graph){

        vector<double> distance(graph.size(), 1e18);
        vector<bool> visited(graph.size());
        
        for(int i = 0; i < graph.size(); i++){
            distance[i] = graph[graph.size() - 2][i];
        }

        visited[graph.size() - 2] = true;

        for(int i = 0; i < graph.size() - 2; i++){
            int now = 0;
            double dist = 1e18;
            for(int j = 0; j < graph.size(); j++){
                if(distance[j] < dist and !visited[j]){
                    dist = distance[j];
                    now = j;
                }
            }
            visited[now] = true;
            for(int next = 0; next < graph.size(); next++){
                if(!visited[next]){
                    if(distance[now] + graph[now][next] < distance[next]){
                        distance[next] = distance[now] + graph[now][next];
                    }
                }
            }
        }

        return distance.back();

    }

    int main(){

        ios_base::sync_with_stdio(0);
        cin.tie(0);

        int a, b;
        cin >> a >> b;

        int n;
        cin >> n;

        vector<pair<int, int>> arr(n);

        for(auto& a : arr){
            cin >> a.first >> a.second;
        }

        arr.emplace_back(0, 0);
        arr.emplace_back(a, b);

        vector<vector<double>> graph(n + 2, vector<double>(n + 2));

        graph[n][n + 1] = get_distance(arr[n], arr[n + 1]);
        graph[n + 1][n] = graph[n][n + 1];

        for(int i = 0; i < n; i++){
            graph[i][n] = max(0.0, get_distance(arr[i], arr[n]) - 1);
            graph[n][i] = graph[i][n];
            graph[i][n + 1] = max(0.0, get_distance(arr[i], arr[n + 1]) - 1);
            graph[n + 1][i] = graph[i][n + 1];
        }

        for(int i = 0; i < n; i++){
            for(int next = i + 1; next < n; next++){
                graph[i][next] = max(0.0, get_distance(arr[i], arr[next]) - 2);
                graph[next][i] = graph[i][next];
            }
        }

        cout << fixed;
        cout.precision(10);
        cout << dijkstra(graph);

        return 0;
    }