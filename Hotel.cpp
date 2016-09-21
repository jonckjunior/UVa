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
#define INF 1e8
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

int n,m;
int hotel[10001];
vvii g;
int estado[10001][101];

int dji(){
    int destino = n-1;
    priority_queue< iii, vector<iii>, greater<iii> > pq; pq.push(make_pair(0,ii(0,0)));
    for(int i = 0; i < g.size(); i++)
        for(int j = 0; j <= 101; j++)
            estado[i][j] = INF;
    estado[0][0] = 0;
    while(!pq.empty()){
        iii frente = pq.top(); pq.pop();
        int d = frente.first, t = frente.second.first, u = frente.second.second;
        //printf("(%d,%d,%d)\n",d,t,u+1 );
        if(u == destino) return d;
        if(t > estado[u][d]) continue;
        if(hotel[u]){
            if(d+1 <= 100 && estado[u][d+1] == INF){
                estado[u][d+1] = 0;
                pq.push(make_pair(d+1,ii(0,u)));
            }
        }
        for(int i = 0; i < g[u].size(); i++){
            ii nodo = g[u][i];
            int distancia = nodo.second, v = nodo.first;
            if(t + distancia <= 600 && t + distancia < estado[v][d]){
                estado[v][d] = t + distancia;
                pq.push(make_pair(d,ii(t+distancia,v)));
            }
        }
    }
    for(int i = 0; i <= 100; i++){
        if(estado[destino][i] < INF) return i;
    }
    return -1;
}



int main(){
    int x,y,t;
    while(scanf("%d",&n) && n && scanf("%d",&m)){
        g.assign(n,vii());
        memset(hotel,0,sizeof hotel);
        for(int i = 0; i < m; i++){
            scanf("%d",&x);
            hotel[x-1] = 1;
        }
        scanf("%d",&m);
        for(int i = 0; i < m ; i++){
            scanf("%d %d %d",&x,&y,&t);
            x--;y--;
            g[x].push_back(ii(y,t));
            g[y].push_back(ii(x,t));
        }
        cout << dji() << endl;
    }
}

