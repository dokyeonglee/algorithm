#include <iostream>
//#include "videoclips.h"

using namespace std;

int parent[31][100000];
int answer[100000];

void videos(int k, int m, int s[]) {

    for(int i = 0; i < k; i++){
        answer[i] = i;
    }

    for(int i = 0; i < k; i++){
        parent[0][i] = s[i];
    }

    for(int i = 1; i < 31; i++){
        for(int j = 0; j < k; j++){
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
        }
    }
    
    --m;

    for(int i = 30; i >= 0; i--){
        if(m & (1 << i)){
            for(int j = 0; j < k; j++){
                answer[j] = parent[i][answer[j]];
            }
        }
    }

}

int clip(int I) {
  return answer[I];
}


#ifndef ONLINE_JUDGE
int main(){

    int k, m;
    cin >> k >> m;

    int s[k];
    for(int i = 0; i < k; i++){
        cin >> s[i];
    }

    videos(k, m, s);

    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        cout << clip(arr[i]) << " ";
    }

    return 0;
}
#endif