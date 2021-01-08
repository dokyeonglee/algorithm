#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Meat{
	int weight;
	int price;
	bool operator < (Meat const& other){//ascending by price, descending by weight
		if(price == other.price){
			return weight > other.weight;
		}
		return price < other.price;
	}
};

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<struct Meat> meats(n);
	int weight, price;
	for(int i = 0; i < n; i++){
		cin >> weight >> price;
		meats[i] = Meat{weight, price};
	}
	
	sort(meats.begin(), meats.end());
	
	weight = price = 0;
	
	int max_price_in_cart = 0;
	
	for(int i = 0; i < n; i++){
		if(weight < m){
			if(meats[i].price == max_price_in_cart){
				price += meats[i].price;	
			}else{
				max_price_in_cart = price = meats[i].price;	
			}
		}else{
			if(meats[i].price != max_price_in_cart and price >= meats[i].price){
				max_price_in_cart = price = meats[i].price;	
			}
		}
		weight += meats[i].weight;
	}
	
	if(weight < m){
		cout << -1 << endl;
	}else{
		cout << price << endl;
	}
	
	return 0;
}