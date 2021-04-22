#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> A(n), B(n), C(n), D(n);
	for(int i = 0; i < n; i++){
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	
	vector<long long> AB(n * n);
	vector<long long> CD(n * n);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			AB[i * n + j] = A[i] + B[j];
			CD[i * n + j] = C[i] + D[j];
		}
	}
	
	sort(AB.begin(), AB.end());
	sort(CD.begin(), CD.end());
	
	long long answer = 0;
	
	for(int i = 0; i < AB.size(); i++){
		answer += upper_bound(CD.begin(), CD.end(), -AB[i]) - lower_bound(CD.begin(), CD.end(), -AB[i]);
	}
	
	cout << answer;
	
	return 0;
}