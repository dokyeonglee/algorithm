#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void print_ip(int ip){
	cout << ((ip & 0xff000000) >> 24) << "." << ((ip & 0xff0000) >> 16) << "." << ((ip & 0xff00) >> 8) << "." << (ip & 0xff) << "\n";
}

int get_msb(unsigned int n){
	n |= (n >> 1);
	n |= (n >> 2);
	n |= (n >> 4);
	n |= (n >> 8);
	n |= (n >> 16);
	return n - (n >> 1);
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	unsigned int ip = 0;
	unsigned int subnet = 0;
	
	for(int i = 0; i < n; i++){
		unsigned int temp_ip = 0;
		string str;
		cin >> str;
		stringstream ss(str);
		string temp;
		while(getline(ss, temp, '.')){
			temp_ip = (temp_ip << 8) | stoi(temp);
		}
		if(i == 0){
			ip = temp_ip;
		}else{
			subnet |= ip ^ temp_ip;
		}
	}
	subnet = get_msb(subnet);
	if(subnet){
		subnet |= subnet - 1;
	}
	subnet = ~subnet;

	print_ip(ip & subnet);
	print_ip(subnet);
	
	return 0;
}