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
#define CTOI(c) c-'a'+1
  
using namespace std;
typedef pair<int,int> ii;
typedef vector< ii > vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef pair<int,vvi> ivvi;
vi dist;
vvi inicio(2,vi(4)), fim(2,vi(4));
vvii g(50000);
map<vvi, int> mapa;
int k = 1;

int dji(){
    priority_queue < pair<int,vvi> , vector< pair<int,vvi> >, greater< pair<int,vvi> > > pq;
    pq.push( make_pair( 0,inicio ) ); 
    dist[mapa[inicio]] = 0;
    int atual, final = mapa[fim];
    while(!pq.empty()){
        ivvi front = pq.top(); pq.pop();
        vvi u = front.second;
        int d = front.first, atual = mapa[u];
        if(d > dist[atual]) continue;
        if(atual == final) return d;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                swap(u[i][j], u[i][j+1]);
                if(mapa[u]==0) mapa[u] = k++;
                //printf("i = %d j = %d\n",i,j);
                //printf("troquei %d com %d\n",u[i][j],u[i][j+1] );
                int v = u[i][j] + u[i][j+1];
                //printf("v = %d\ndist[destino] = %d\n",v,dist[mapa[u]]);
                if(dist[atual] + v < dist[mapa[u]]){
                    dist[mapa[u]] = dist[atual] + v;
                    //printf("Adding with price = %d\n",dist[mapa[u]]);
                    pq.push(make_pair(dist[mapa[u]], u));
                }
                swap(u[i][j], u[i][j+1]);
            } 
        }
        for(int j =0 ; j < 4; j++){
            swap(u[0][j], u[1][j]);
            if(mapa[u]==0) mapa[u] = k++;
            int v = u[0][j] + u[1][j];
            if(dist[atual] + v < dist[mapa[u]]){
                    dist[mapa[u]] = dist[atual] + v;
                    //printf("Adding with price = %d\n",dist[mapa[u]]);
                    pq.push(make_pair(dist[mapa[u]], u));
            }
            swap(u[0][j], u[1][j]);
        }
    }
    return dist[mapa[fim]];
}   



int main() {
    
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 4; j++)
            scanf("%d",&inicio[i][j]);
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 4; j++)
            scanf("%d",&fim[i][j]);
    dist.assign(50000,INF);
    mapa[inicio] = k++;
    mapa[fim] = k++;
    //printf("mapa[inicio] = %d\nmapa[fim] = %d\n",mapa[inicio],mapa[fim]);
    cout << dji() << endl;
}
