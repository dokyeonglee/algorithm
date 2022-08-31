#include <iostream>
#include <set>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	multiset<pair<double, pair<int, int>>> ms;
	vector<double> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		ms.insert(make_pair(arr[i], make_pair(i, 1)));
	}
	
	int m;
	cin >> m;
	
	double answer = ms.rbegin()->first - ms.begin()->first;
	for(int i = 0; i < m; i++){
		auto temp = *ms.rbegin();
		ms.erase(ms.lower_bound(temp));
		temp.first = arr[temp.second.first] / ++temp.second.second;
		ms.insert(temp);
		answer = min(answer, ms.rbegin()->first - ms.begin()->first);
	}
	
	cout << fixed;
	cout << setprecision(12) << answer;
	return 0;
}