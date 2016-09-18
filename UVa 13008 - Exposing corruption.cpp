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

int d,p,r,b,preco,politicos;
vi pd,pp;
vvi AdjDeadly, AdjParty;
vi marcadop, marcadod;

void dfs(int u, int flag, int porra_perdi_mo_tempo_nisso){
    if(flag) politicos++;
    else politicos--;
    if(porra_perdi_mo_tempo_nisso){
        marcadod[u] = 1;preco+=pd[u];
        for(int i = 0; i < AdjDeadly[u].size(); i++)
            if(marcadop[AdjDeadly[u][i]] == 0)
                dfs(AdjDeadly[u][i],!flag, !porra_perdi_mo_tempo_nisso);
    }
    else{
        marcadop[u] = 1;preco+=pp[u];
        for(int i = 0; i < AdjParty[u].size(); i++)
            if(marcadod[AdjParty[u][i]] == 0)
                dfs(AdjParty[u][i],!flag, !porra_perdi_mo_tempo_nisso);   
    }
}

void ks(){
    int resparty, resdeadly;
    marcadop.assign(p,0);
    marcadod.assign(d,0);
    vii pesos;
    // para party party party
    for(int i = 0; i < d; i++){
        if(marcadod[i] == 0){
            preco = 0;
            politicos=0;
            dfs(i,1,1);
            pesos.push_back(make_pair(preco,politicos));
        }
    }
    int dp[10001];
    memset(dp,0,sizeof dp);
    for(int i = 0; i < pesos.size(); i++){
        ii u = pesos[i];
        for(int w = b; w >= u.first ; w--){
            dp[w] = max(dp[w],dp[w-u.first] + u.second);
        }
    } 
    resparty = dp[b] + p;
    pesos.clear();
    marcadop.assign(p,0);
    marcadod.assign(d,0);
    for(int i = 0; i < p; i++){
        if(marcadop[i] == 0){
            preco = 0;
            politicos = 0;
            dfs(i,1,0);
            pesos.push_back(make_pair(preco,politicos));
        }
    }
    memset(dp,0,sizeof dp);
    for(int i = 0; i < pesos.size(); i++){
        ii u = pesos[i];
        for(int w = b; w >= u.first ; w--){
            dp[w] = max(dp[w],dp[w-u.first] + u.second);
        }
    }
    resdeadly = dp[b] + d;
    cout << resdeadly << " " << resparty << endl;
}

int main() {
    int x,y;
    while(scanf("%d %d %d %d",&d,&p,&r,&b) != EOF){
        pd.resize(d);pp.resize(p);
        AdjParty.assign(p,vi());AdjDeadly.assign(d,vi());

        for(int i = 0 ; i < d; i++)
            scanf("%d",&pd[i]);
        for(int i = 0 ; i < p; i++)
            scanf("%d",&pp[i]);
        for(int i = 0; i < r; i++){
            scanf("%d %d",&x,&y);
            x--;y--;
            AdjDeadly[x].push_back(y);
            AdjParty[y].push_back(x);
        }
        ks();
    }
}
