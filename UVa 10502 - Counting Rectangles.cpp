#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 1e9
 
using namespace std;

char grid[105][105];

int main() {
    int n,m;
    string s;
    while(scanf("%d",&n), n){
        scanf("%d",&m);
        getline(cin,s);
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m; j++)
                scanf("%c",&grid[i][j]);
            getline(cin,s);
        }
        int quadrados=0;
        int valid;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int a = i; a < n; a++){
                    for(int b = j; b < m; b++){
                        valid = 1;
                        for(int c = i; c <= a && valid; c++){
                            for(int d = j; d <= b && valid; d++){
                                if(grid[c][d] != '1') valid = 0;
                            }
                        }
                        if(valid) quadrados++;
                    }
                }
            }
        }

        cout << quadrados << endl;

    }


    return 0;
}
