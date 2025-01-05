#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double f(vector<double>& coefficient, double x){
    double result = 0;
    for(int i = 0; i < coefficient.size(); i++){
        result = result * x + coefficient[i];
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    vector<double> coefficient(k + 1);
    for(auto& a : coefficient){
        cin >> a;
    }

    vector<double> integral_coefficient(k + 2);
    for(int i = 0; i <= k; i++){
        integral_coefficient[i] = coefficient[i] / (k + 1 - i);
    }

    int a, b, n;
    cin >> a >> b >> n;

    double integral = f(integral_coefficient, b) - f(integral_coefficient, a);

    double delta_x = (b - a) / (double)n;

    double left = 0;
    double right = delta_x;

    double answer = -1;

    for(int j = 0; j < 100; j++){
        double mid = (left + right) / 2;
        double sum = 0;
        for(int i = 0; i < n; i++){
            sum += f(coefficient, a + i * delta_x + mid);
        }
        sum *= delta_x;
        if(fabs(sum - integral) < 1e-4){
            answer = mid;
            break;
        }else if(sum < integral){
            left = mid;
        }else{
            right = mid;
        }
    }

    cout << answer;

    return 0;

}