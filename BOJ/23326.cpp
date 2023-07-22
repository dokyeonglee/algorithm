    #include <iostream>
    #include <vector>
    #include <set>

    using namespace std;

    int main(){

        ios_base::sync_with_stdio(0);
        cin.tie(0);

        int n, q;
        cin >> n >> q;

        set<int> s;

        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            if(x){
                s.insert(i);
            }
        }

        int now = 0;

        while(q--){
            int c;
            cin >> c;
            if(c == 1){
                int x;
                cin >> x;
                x--;
                if(s.count(x)){
                    s.erase(x);
                }else{
                    s.insert(x);
                }
            }else if(c == 2){
                int x;
                cin >> x;
                now = (now + x) % n;
            }else{
                if(s.size() == 0){
                    cout << -1;
                }else{
                    auto it = s.lower_bound(now);
                    if(it == s.end()){
                        cout << n - now + *s.begin();
                    }else{
                        cout << *it - now;
                    }
                }
                cout << "\n";
            }
        }

        return 0;
    }