#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    long long answer = 0;
    stack<pair<int, int>> s;
    
    for(int i = 0; i < n; i++){
    	
        int x;
        cin >> x;
        
        pair<int, int> p = make_pair(x, 1);
        
        while(!s.empty() and s.top().first <= x){
            
            if(s.top().first == x){
                p.second = s.top().second + 1;
            }else{
                p.second = 1;
            }
            
            answer += s.top().second;
            s.pop();
            
        }
        
        if(!s.empty()){
            answer++;
        }
        
        s.push(p);
        
    }
    
    cout << answer;
    
    return 0;
}
