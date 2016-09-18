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

int tracks[21];

int n,t,somatotal,bit, ans;
vector<int> v;

void back_track(int w, int res, int i){
    if(w < 0) return;
    if(w < somatotal){
        ans = res;
        somatotal = w;
    }
    if(i >= t) return;
    back_track(w,res,i+1);
    back_track(w-tracks[i], res | (1<<i), i+1);
}

int main() {

    while(scanf("%d %d",&n,&t)!=EOF){
        for(int i = 0; i < t; i++)
            scanf("%d",&tracks[i]);
        somatotal = 1e9;
        back_track(n,0,0);
        for(int i = 0; i < t; i++)
            if(ans & (1 << i))
                printf("%d ",tracks[i]);
        printf("sum:%d\n",n-somatotal);
    }

}
