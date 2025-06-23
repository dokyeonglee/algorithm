#include <iostream>
#include <vector>

using namespace std;

void match_lead_and_tin(vector<int>& lead_to_tin) {
    for (int lead = lead_to_tin.size() - 1; lead >= 1; --lead) {
        if (lead_to_tin[lead] == 0) {
            int next_pow_2 = 1 << (32 - __builtin_clz(lead));
            lead_to_tin[next_pow_2 - lead] = lead;
            lead_to_tin[lead] = next_pow_2 - lead;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> lead_to_tin(n + 1);
    match_lead_and_tin(lead_to_tin);

    for (int lead = 1; lead <= n; ++lead) {
        cout  << lead_to_tin[lead] << '\n';
    }

    return 0;
}