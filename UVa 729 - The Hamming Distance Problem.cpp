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

int n, h;
vector<int> v;

void backtrack(int i, int mark, int c){
    //printf("---INFINITE---\n" );
    if(i >= n){
        if(c != h) return;
        for(int j = 0; j < n; j++){
            if(mark&bit(j))
                printf("1");
            else
                printf("0");
        }
        printf("\n");
        return;
    }
    backtrack(i+1,mark,c);
    backtrack(i+1,mark|(1<<i),c+1);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&h);
        v.clear();
        backtrack(0,0,0);
        if(t) cout << endl; 
    }        
}

