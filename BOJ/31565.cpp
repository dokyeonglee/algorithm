#include <iostream>
#include <vector>

using namespace std;

int month_to_day[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

int leap_year_count(int year){
    return year / 4 - year / 100 + year / 400;
}

int convert_to_day(int year, int month, int day){

    int result = (year - 1) * 365 + month_to_day[month] + day;

    result += leap_year_count(year - 1);

    if(year % 4 == 0){
        if(year % 100 != 0 or year % 400 == 0){
            if(month > 2){
                result++;
            }
        }
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    int year, month, day;

    cin >> year >> month >> day;
    int jonghyun = convert_to_day(year, month, day);

    cin >> year >> month >> day;
    int youngdo = convert_to_day(year, month, day);

    int t, n;
    cin >> t >> n;

    vector<int> cost(n + 1);
    vector<int> value(n + 1);

    for(int i = 1; i <= n; i++){
        int x;
        cin >> x >> cost[i] >> value[i];
        if(x == 3){
            value[i] *= 30;
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(t + 1));

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < cost[i]; j++){
            dp[i][j] = dp[i - 1][j];
        }
        for(int j = cost[i]; j <= t; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + value[i]);
        }
    }

    cout << abs(jonghyun + dp[n][t] - youngdo);

    return 0;
}