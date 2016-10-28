#include <bits/stdc++.h>
#define INF 1e8
using namespace std;
long long int coin[10] = {5,10,20,50,100,200}, numcoin = 6,res, start;
int qt[10];
double aux;

int change(int x){
    int x1 = x/200;
    x = x%200;
    int x2 = x / 100;
    x = x%100;
    int x3 = x / 50;
    x = x%50;
    int x4 = x / 20;
    x = x%20;
    int x5 = x / 10;
    x = x%10;
    int x6 = x / 5;
    x = x%5;
    return x1 + x2 + x3 + x4+ x5 + x6;
}

long long int solve(int id, int sum, int nc, int ct){
    if(nc < 0 || sum < res)       return INF;
    if(id == numcoin)             return ct + change(sum-res);
    int esq = solve(id+1,sum,qt[id+1], ct);
    int dir = solve(id, sum - coin[id], nc-1, ct-1);
    return min(esq,dir);
}

int main(){
    while(cin >> qt[0]>> qt[1]>> qt[2]>> qt[3]>> qt[4]>> qt[5] && qt[0]+qt[1]+qt[2]+qt[3]+qt[4]+qt[5] != 0){
        cin >> aux;
        res = aux*100;
        int ct = 0;
        start = 0;
        for(int i = 0; i < 6; i++){
            ct += qt[i];
            start += qt[i]*coin[i];
        }
        //memset(DP, -1, sizeof DP);
        printf("%3lld\n",solve(0, start, qt[0], ct) );
    }
}
