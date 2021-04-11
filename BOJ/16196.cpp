#include <iostream>
#include <unordered_map>


using namespace std;

bool is_leap(int yyyy){
	return (yyyy % 4 == 0 and yyyy % 100 != 0) or yyyy % 400 == 0;
}

bool valid_check_sum(string id, int check_sum){
	
	for(int i = 0; i < 17; i++){
		check_sum += (id[i] - '0') * (1 << (17 - i));
	}
	
	return check_sum % 11 == 1;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string id;
	cin >> id;
	
	int max_day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	int local_code = stoi(id.substr(0, 6));
	int yyyy = stoi(id.substr(6, 4));
	int mm = stoi(id.substr(10, 2));
	int dd = stoi(id.substr(12, 2));
	int order_code = stoi(id.substr(14, 3));
	int check_sum;
	
	int n;
	cin >> n;
	
	unordered_map<int, bool> valid_local_code;
	for(int i = 0; i < n; i++){
		int local;
		cin >> local;
		valid_local_code[local] = true;
	}
	
	if(id[17] == 'X'){
		check_sum = 10;
	}else{
		check_sum = id[17] - '0';
	}
	
	bool valid_date;
	
	if(is_leap(yyyy)){
		max_day[2] = 29;
	}
	
	if(yyyy >= 1900 and yyyy <= 2011 and mm >=1 and mm <= 12 and dd >= 1 and dd <= max_day[mm]){
		valid_date = true;	
	}else{
		valid_date = false;
	}
	
	if(valid_local_code[local_code] and valid_date and order_code != 0 and valid_check_sum(id, check_sum)){
		if(order_code % 2 == 0){
			cout << "F";
		}else{
			cout << "M";
		}
	}else{
		cout << "I";
	}
	
	return 0;
}