#include <iostream>
#include <vector>

using namespace std;

vector<unsigned long long> convert_base_string_to_chunks(const string& str, int base){
    vector<unsigned long long> result(2);
    for(auto& c : str){
        int digit = c - '0';
        result[0] = result[0] * base + digit;
        result[1] = result[1] * base + (result[0] >> 40);
        result[0] &= (1ull << 40) - 1;
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int u, v;
    cin >> u >> v;

    string ras_power;
    string auq_power;

    cin >> ras_power >> auq_power;

    const int RAS = -1;
    const int AUQ = 1;
    const int DRAW = 0;

    int winner = DRAW;

    if(u == v){
        if(ras_power > auq_power){
            winner = RAS;
        }else if(ras_power < auq_power){
            winner = AUQ;
        }
    }else if(ras_power.size() < 22){
        auto ras = convert_base_string_to_chunks(ras_power, u);
        auto auq = convert_base_string_to_chunks(auq_power, v);
        if(ras > auq){
            winner = RAS;
        }else if(ras < auq){
            winner = AUQ;
        }
    }else{
        if(u > v){
            winner = RAS;
        }else{
            winner = AUQ;
        }
    }

    if(winner == RAS){
        cout << "ras";
    }else if(winner == AUQ){
        cout << "auq";
    }else{
        cout << "rasauq";
    }

    return 0;

}