#include <iostream>
#include <cstdio>
using namespace std;

int coin[1005];

int main() {
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            scanf("%d",&coin[i]);
        int sum = 0, numcoin = 0;
        for(int i = 0; i < n-1; i++){
            if(sum + coin[i] < coin[i+1]) numcoin++,sum+=coin[i];
        }
        cout << numcoin+1 << endl;
    }    
    return 0;
}
