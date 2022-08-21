#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<int, pair<int, int>>> arr(n);
	vector<int> x(n);
	vector<int> y(n);
	
	for(int i = 0; i < n; i++){
		cin >> arr[i].second.first >> arr[i].second.second >> arr[i].first;
		x[i] = arr[i].second.first;
		y[i] = arr[i].second.second;
	}

	sort(arr.rbegin(), arr.rend());
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	
	int answer = 987654321;
	
	for(int i = 0; i < n; i++){
		for(int ii = i; ii < n; ii++){
			for(int j = 0; j < n; j++){
				for(int jj = j; jj < n; jj++){
					int cnt = 0;
					int sum = 0;
					for(int a = 0; a < n; a++){
						if(!(arr[a].second.first >= x[i] and arr[a].second.first <= x[ii] 
							and arr[a].second.second >= y[j] and arr[a].second.second <= y[jj])){
								cnt++;
								sum += arr[a].first;
						}
					}
					if(answer <= cnt){
						continue;
					}
					if(sum >= 2 * (x[ii] - x[i] + y[jj] - y[j])){
						answer = cnt;
					}else{
						for(int a = 0; a < n; a++){
							if(arr[a].second.first >= x[i] and arr[a].second.first <= x[ii] 
							and arr[a].second.second >= y[j] and arr[a].second.second <= y[jj]){
								cnt++;
								sum += arr[a].first;
								if(answer <= cnt){
									break;
								}
								if(sum >= 2 * (x[ii] - x[i] + y[jj] - y[j])){
									answer = cnt;
									break;
								}
							}
						}	
					}
				}
			}
		}
	}
	
	cout << answer;
	
	return 0;
}