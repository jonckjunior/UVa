#include <iostream>
#include <algorithm>
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
#define INF 1e9
#define NINF -1e9
#define CTOI(c) c-'a'+1
#define MAXIMO 100
#define bit(i) (1<<i)
using namespace std;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector< ii > vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef pair<int,vvi> ivvi;
    
int n,e;
vvii g;
int estado[50005][2];

int dji(){
    int destino = n-1;
    priority_queue<iii,vector<iii>, greater<iii> > pq; pq.push(make_pair(0,ii(0,0)));
    //memset(estado, INF, sizeof estado);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 2; j++)
            estado[i][j] = INF;
    estado[0][0] = 0;
    while(!pq.empty()){
        iii frente = pq.top(); pq.pop();
        int d = frente.first, impar = frente.second.first, u = frente.second.second;
        if(u == destino && !impar) return d;
        if(d > estado[u][impar]) continue;
        for(int i = 0; i < g[u].size(); i++){
            ii nodo = g[u][i];
            int distancia = nodo.second, v = nodo.first;
            if(d + distancia < estado[v][!impar]){
                estado[v][!impar] = d+ distancia;
                pq.push(make_pair(d+distancia,ii(!impar,v)));
            }
        }
    }
    return -1;
}
    
int main(){
    int x,y,w;
    while(scanf("%d %d",&n,&e)!=EOF){
        g.assign(n,vii());
        for(int i = 0; i < e; i++){
            scanf("%d %d %d",&x,&y,&w);
            x--;y--;
            g[x].push_back(ii(y,w));
            g[y].push_back(ii(x,w));
        }
        cout << dji() << endl;
    }
}

