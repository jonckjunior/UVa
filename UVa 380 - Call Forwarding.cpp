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

struct nodo{
    int comeco,fim;
    string v;
    nodo(){}
    nodo(int c, int f, string x){comeco = c; fim = f; v = x;}
};

string dfs(int tempo, string atual, map<string,int> &marcados, map<string,vector<nodo> > &m){
    if(marcados[atual]) return "9999";
 
    marcados[atual] = 1;
    for(int i = 0; i < m[atual].size(); i++){
        if(tempo >= m[atual][i].comeco && tempo <= m[atual][i].fim)
            return dfs(tempo,m[atual][i].v, marcados, m);
    }
    return atual;
}

int main(){
    int t, comeco, duracao, tempo, caso = 0;
    string s, destino;
    scanf("%d",&t);
    getline(cin,s);
    printf("CALL FORWARDING OUTPUT\n");
    while(t--){
        printf("SYSTEM %d\n",++caso );
        map<string,vector<nodo> > m;
        while(cin >> s && s != "0000"){
            cin >> comeco >> duracao >> destino;
            m[s].push_back(nodo(comeco, comeco + duracao, destino));
        }
        while(cin >> tempo && tempo != 9000 && cin >> s){
            map<string,int> marcados;            
            printf("AT %04d CALL TO %s RINGS ",tempo,s.c_str());
            cout << dfs(tempo,s,marcados,m) << endl;
        }
    }
    printf("END OF OUTPUT\n");
}

