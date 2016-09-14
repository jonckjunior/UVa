#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BRANCO 1
#define PRETO 2
#define MISTO 3
#define INF 10001
 
using namespace std;


int main() {
    int n,p,x,y;
    scanf("%d %d",&n,&p);
    int grid[n][n];
    memset(grid, 0, sizeof grid);
    for(int i = 0; i < p; i++){
        scanf("%d %d",&x,&y);
        grid[x-1][y-1] = PRETO;
    }
    for(int i = 0; i < p; i++){
        scanf("%d %d",&x,&y);
        grid[x-1][y-1] = BRANCO;
    }
    int preto=p, branco=p,marcador,valid;
    int t = n;
    while(t > 0){
        for(int i = 0; i < t; i++){
            for(int j = 0; j < t; j++){
                //printf("(%d,%d)\n", i,j);
                if(i != t-1 && j != t-1){
                    marcador = grid[i][j];
                    for(int a = i; a < i+2 && marcador!=3; a++){
                        for(int b = j; b < j+2 && marcador!=3; b++){
                            if(marcador == 0 && grid[a][b] != 0) marcador = grid[a][b];
                            else if(marcador != 0 && grid[a][b] != 0 && marcador != grid[a][b]) marcador = 3;
                        }
                    }
                    //printf("marcador = %d\n",marcador);
                    if(marcador == 3) grid[i][j] = 3;
                    else if(marcador == PRETO) grid[i][j] = PRETO,preto++;
                    else if(marcador == BRANCO) grid[i][j] = BRANCO,branco++;
                    else if(marcador == 0) grid[i][j] = 0;
                }
            }
        }
        t--;
    }
    printf("%d %d\n",preto,branco);
    return 0;
}
