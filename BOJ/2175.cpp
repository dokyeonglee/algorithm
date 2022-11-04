#include <iostream>
#include <vector>
#include <iomanip>
 
using namespace std;
 
double triangle(pair<double, double>& a, pair<double, double>& b, pair<double, double>& c){
	return abs((b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second)) / 2.0;
}

int main() {
 
	vector<pair<double, double>> arr(8);
	for(int i = 0; i < 8; i += 2){
		cin >> arr[i].first >> arr[i].second;
	}
 
	for(int i = 1; i < 8; i += 2){
		arr[i].first = (arr[i - 1].first + arr[(i + 1) % 8].first) / 2;
		arr[i].second = (arr[i - 1].second + arr[(i + 1) % 8].second) / 2;
	}
 
	double answer1 = triangle(arr[0], arr[2], arr[4]);
	double answer2 = triangle(arr[0], arr[4], arr[6]);
	double total = answer1 + answer2;
 
	for(int i = 0; i < 8; i += 2){
		double result1 = triangle(arr[i], arr[(i + 2) % 8], arr[(i + 3) % 8]);
		double result2 = triangle(arr[i], arr[(i + 2) % 8], arr[(i + 4) % 8]);
		double result3 = triangle(arr[i], arr[(i + 5) % 8], arr[(i + 6) % 8]);
		if(abs(total - 2 * result1) < abs(answer1 - answer2)){
			answer1 = result1;
			answer2 = total - answer1;
		}
		if(abs(total - 2 * result2) < abs(answer1 - answer2)){
			answer1 = result2;
			answer2 = total - answer1;
		}
		if(abs(total - 2 * result3) < abs(answer1 - answer2)){
			answer1 = result3;
			answer2 = total - answer1;
		}
	}
	
	for(int i = 1; i < 8; i += 2){
		double result1 = triangle(arr[i], arr[(i + 1) % 8], arr[(i + 2) % 8]);
		double result3 = triangle(arr[i], arr[(i + 1) % 8], arr[(i + 3) % 8]) + triangle(arr[i], arr[(i + 3) % 8], arr[(i + 4) % 8]);
		double result5 = triangle(arr[i], arr[(i + 6) % 8], arr[(i + 7) % 8]);
		if(abs(total - 2 * result1) < abs(answer1 - answer2)){
			answer1 = result1;
			answer2 = total - answer1;
		}
		if(abs(total - 2 * result3) < abs(answer1 - answer2)){
			answer1 = result3;
			answer2 = total - answer1;
		}
		if(abs(total - 2 * result5) < abs(answer1 - answer2)){
			answer1 = result5;
			answer2 = total - answer1;
		}
	}
 
	cout.fixed;
	cout.precision(10);
	
	if(answer1 > answer2){
		swap(answer1, answer2);
	}
 
	cout << answer1 << " " << answer2;
 
	return 0;
}