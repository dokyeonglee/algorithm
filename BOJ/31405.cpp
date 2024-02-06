#include <iostream>
#include <vector>

using namespace std;

double get_area(pair<long long, long long>& a, pair<long long, long long>& b, pair<long long, long long>& c){
    return ((b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first)) / 2.0;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    vector<pair<long long, long long>> arr(n);
    for(auto& a : arr){
        cin >> a.first >> a.second;
    }

    double area_sum = 0;
    vector<double> area(n - 2);

    for(int i = 0; i < n - 2; i ++){
        area[i] = get_area(arr[0], arr[i + 1], arr[i + 2]);
        area_sum += area[i];
    }

    double temp = 0;
    int idx = 0;

    for(int i = 0; i < n - 2; i++){
        if(temp + area[i] < area_sum / 2){
            temp += area[i];
        }else{
            idx = i;
            break;
        }
    }

    cout << fixed;
    cout.precision(12);

    cout << "YES\n";
    cout << "1 0.000000000000\n";
    cout << idx + 2 << " " << (area_sum / 2 - temp) / area[idx];

    return 0;
}