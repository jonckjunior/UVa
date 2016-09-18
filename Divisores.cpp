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

int main() {

    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    bool found = false;
    if(a%b == 0 || d%c == 0){
        printf("-1\n");
        exit(0);
    }
    for(int n = a, i=0 ; i <= sqrt(c) + 1 && n <= c && !found; n+=a){
        if(n%b != 0 && c%n == 0 && d%n != 0){printf("%d\n",n);found=true;}
    }
    if(!found) printf("-1\n");

}
