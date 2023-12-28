#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int x_min, y_min, x_max, y_max;
    cin >> x_min >> y_min >> x_max >> y_max;

    long long xl_sum = 0;
    long long yl_sum = 0;
    long long l_sum = 0;
    long long x2l_y2l_sum = 0;

    for(int i = 0; i < n; i++){
        long long x, y, l;
        cin >> x >> y >> l;
        xl_sum += x * l;
        yl_sum += y * l;
        l_sum += l;
        x2l_y2l_sum += x * x * l + y * y * l;
    }

    if(l_sum == 0){
        cout << 0;
        return 0;
    }

    long long answer = (1ll << 63) - 1;

    for(long long xc = xl_sum / l_sum - 1; xc <= xl_sum / l_sum + 1; xc++){
        long long yc = y_min - 1;
        answer = min(answer, l_sum * (xc * xc + yc * yc) - 2 * xc * xl_sum - 2 * yc * yl_sum);
        yc = y_max + 1;
        answer = min(answer, l_sum * (xc * xc + yc * yc) - 2 * xc * xl_sum - 2 * yc * yl_sum);
    }

    for(long long yc = yl_sum / l_sum - 1; yc <= yl_sum / l_sum + 1; yc++){
        long long xc = x_min - 1;
        answer = min(answer, l_sum * (xc * xc + yc * yc) - 2 * xc * xl_sum - 2 * yc * yl_sum);
        xc = x_max + 1;
        answer = min(answer, l_sum * (xc * xc + yc * yc) - 2 * xc * xl_sum - 2 * yc * yl_sum);

    }

    cout << answer + x2l_y2l_sum;

    return 0;
}