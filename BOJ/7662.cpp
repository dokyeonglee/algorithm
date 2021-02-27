#include <iostream>
#include <set>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	for(int test_case = 0; test_case < T; test_case++){
		
		multiset<int> bi_pq;
		
		int n;
		cin >> n;
		
		for(int i = 0; i < n; i++){
			
			char c;
			cin >> c;
	
			int x;
			cin >> x;
			
			if(c == 'I'){
				bi_pq.insert(x);
			}else{
				if(bi_pq.empty()){
					continue;
				}else if(x == 1){
					auto it = bi_pq.end();
					it--;
					bi_pq.erase(it);
				}else{
					bi_pq.erase(bi_pq.begin());	
				}
			}
		}
		
		if(bi_pq.empty()){
			cout << "EMPTY\n";
		}else{
			auto it = bi_pq.end();
			it--;
			cout << *it << " " << *bi_pq.begin() << '\n';
		}
	}
	
	return 0;
}