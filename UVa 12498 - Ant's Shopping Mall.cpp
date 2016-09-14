#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define INF 1e9
 
using namespace std;

char grid[55][55];

int main() {
    string s;
    int t,n,m,caso=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        getline(cin,s);
        for(int i =0 ; i < n; i++){
            for(int j = 0; j < m; j++)
                scanf("%c",&grid[i][j]);
            getline(cin,s);
        }

        int mini = 1e9, atual;
        printf("Case %d: ",++caso );
        for(int i = 0; i < m; i++){
            atual = 0;
            for(int j = 0; j < n; j++){
                int dir=0, esq=0;
                for(int k = i; k < m && grid[j][k] == '1'; k++){
                    if(k == m-1) dir = INF;
                    else dir++;
                }
                for(int k = i; k >=0 && grid[j][k] == '1'; k--){
                    if(k == 0) esq = INF;
                    else esq++;
                }
                atual+= min(esq,dir);
                if(atual >= INF) break;
            }
            mini = min(mini,atual);
        }
        if(mini >= INF) cout << "-1" << endl;
        else cout << mini << endl;
    }
    
    return 0;
}
