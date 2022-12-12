#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

long long get_det(vector<vector<long long>>& arr){
	long long det = 0;
	int sign = 1;
	for(int i = 0; i < 3; i++){
		det += sign * (arr[0][i] * (arr[1][1 - (i > 0)] * arr[2][2 - (i == 2)] - arr[1][2 - (i == 2)] * arr[2][1 - (i > 0)]));
		sign = -sign;
	}
	return det;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	
	cout << fixed;
	cout.precision(3);
	
	while(t--){
		vector<vector<long long>> arr(3, vector<long long>(3));
		vector<long long> b(3);
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				cin >> arr[i][j];
			}
			cin >> b[i];
		}
		
		long long det = get_det(arr);
		vector<double> x_v(3);
		vector<long long> det_v(3);
		
		for(int i = 0; i < 3; i++){
			auto temp(arr);
			for(int j = 0; j < 3; j++){
				temp[j][i] = b[j];
			}
			det_v[i] = get_det(temp);
		}
		
		if(det != 0){
			for(int i = 0; i < 3; i++){
				double result = (double)det_v[i] / det;
				if(abs(result) < 5e-4){
					result = 0.0;
				}
				x_v[i] = result;
			}
		}
		
		for(int i = 0; i < 3; i++){
			cout << det_v[i] << " ";
		}
		cout << det << "\n";
		
		if(det == 0){
			cout <<  "No unique solution";
		}else{
			cout << "Unique solution: ";
			for(int i = 0; i < 3; i++){
				cout << x_v[i] << " ";
			}
		}
		
		cout << "\n\n";
		
	}
	
	return 0;
}