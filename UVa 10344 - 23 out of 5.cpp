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
using namespace std;
typedef pair<int,int> ii;
typedef vector< ii > vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef pair<int,vvi> ivvi;

int v[5];
bool found;
#define MAX 4

void backtrack(int n, int sum){
    if(n >= MAX){
        //printf("Analisando %d com sum = %d\n",n,sum );
        if(sum == 23)
            found = true;
        return;
    }
    backtrack(n+1,sum+v[n+1]);
    backtrack(n+1,sum-v[n+1]);
    backtrack(n+1,sum*v[n+1]);
}

int main(){
    while(scanf("%d %d %d %d %d",&v[0],&v[1],&v[2],&v[3],&v[4])  && v[0] + v[1] + v[2] + v[3] + v[4] != 0){
        //scanf("%d %d %d",&v[0],&v[1],&v[2]);
        found = false;
        sort(v,v+5);
        do{
            backtrack(0,v[0]);
        }while(next_permutation(v, v+5) && !found);
        if(found) cout << "Possible" << endl;
        else cout << "Impossible" << endl;
    }
}

