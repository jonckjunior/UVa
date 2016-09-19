#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <map>
#include <queue>
#define BRANCO 1
#define PRETO 2
#define MISTO 3
#define INF 10000001
#define NINF -1e9
#define CTOI(c) c-'a'+1
#define MAXIMO 100
using namespace std;
typedef pair<int,int> ii;
typedef vector< ii > vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef pair<int,vvi> ivvi;

int m,n,token;
bool existe = false;
int g[11][11], r[11][11], marcado[11];

void dfs(int u, int length, vector<int> v){
    if(length > n) return;
    v.push_back(u+1);
    if(length == n){
        existe = true;
        printf("(");
        for(int i = 0; i < v.size();i++){
            printf("%d",v[i]);
            if(i != v.size() -1) printf(",");
        }
        printf(")\n");
        return;
    }
    marcado[u] = 1;
    for(int i = 0; i < m; i++)
        if(g[u][i] && !marcado[i])
            dfs(i,length+1,v);
    marcado[u] = 0;
}

int main(){
    bool espaco = false;
    while(scanf("%d %d",&m,&n) != EOF){
        if(espaco) cout << endl;
        memset(g,0,sizeof g);
        memset(r,0,sizeof r);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < m; j++)
                scanf("%d",&g[i][j]),r[i][j] = g[i][j];
        memset(marcado, 0, sizeof marcado);
        vector<int> ppp;
        existe = false;
        dfs(0,0,ppp);
        if(!existe) cout << "no walk of length " << n << endl;
        espaco = true;
        if(scanf("%d",&token) == EOF) break;
    }    


    return 0;
}

