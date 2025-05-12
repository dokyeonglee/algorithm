#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int calculate_min_conversions(string& veins, int monster_hp){

    int number_of_veins = veins.size();

    monster_hp = min(monster_hp, number_of_veins);

    if(monster_hp == 1){
        return 0;
    }

    int min_conversions = 0;

    if(monster_hp == 2){
        for(int i = 1; i < number_of_veins; i++){
            if(veins[i - 1] == veins[i]){
                veins[i] = '.';
                min_conversions++;
            }
        }
        return min_conversions;
    }else if(monster_hp == 3){
        string pattern = "RSW";
        min_conversions = number_of_veins;
        do{
            int conversions = 0;
            for(int i = 0; i < number_of_veins; i++){
                if(veins[i] != pattern[i % 3]){
                    conversions++;
                }
            }
            min_conversions = min(min_conversions, conversions);
        }while(next_permutation(pattern.begin(), pattern.end()));
        return min_conversions;
    }

    return -1;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int number_of_veins, monster_hp;
    cin >> number_of_veins >> monster_hp;

    string veins;
    cin >> veins;

    cout << calculate_min_conversions(veins, monster_hp);

    return 0;

}