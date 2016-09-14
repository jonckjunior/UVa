#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define INF 1e9
 
using namespace std;

char grid[105][105];

int main() {
    string s;
    int t,n,m,q,x,y;
    scanf("%d",&t);
    getline(cin,s);
    while(t--){
        scanf("%d %d %d",&n,&m,&q);
        getline(cin,s);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                scanf("%c",&grid[i][j]);
            getline(cin,s);
        }
        printf("%d %d %d\n",n,m,q);
        for(int i = 0; i < q; i++){
            scanf("%d %d",&x,&y);
            char atual = grid[x][y];

            int res = min(x, min(n-x-1, min(y,m-y-1))), tmax = 0;
            for(int l = res; l >= 0; l--){
                bool valid = true;
                for(int a = x - l; a <= x+l && valid; a++){                    
                    for(int b = y - l; b <= y + l && valid; b++){
                        if(grid[a][b] != atual){valid = false;break;}
                    }
                }
                if(valid){
                    tmax = l;
                    break;
                }
            }
            cout << tmax*2 +1 << endl;
        }
    }
    return 0;
}
