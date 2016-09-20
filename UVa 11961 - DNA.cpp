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
#define INF 10000001
#define NINF -1e9
#define CTOI(c) c-'a'+1
#define MAXIMO 100
#define bit(i) (1<<i)
using namespace std;
typedef pair<int,int> ii;
typedef vector< ii > vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef pair<int,vvi> ivvi;

int n,k;
char comb[] = "ACGT";
vector<string> vs;
void backtrack(int i, string s, int m){
    if(m > k) return;
    if(i == n){vs.push_back(s);return;}
    char aux;
    for(int j = 0; j < 4; j++){
        aux = s[i];
        s[i] = comb[j];
        if(aux == comb[j])
            backtrack(i+1,s,m);
        else
            backtrack(i+1,s,m+1);
        s[i] = aux;
    }
}

int main(){
    int t;
    string s;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        cin >> s;
        vs.clear();
        backtrack(0,s,0);
        cout << vs.size() << endl;
        for(int i = 0; i < vs.size(); i++)
            cout << vs[i] << endl;
    }
}

