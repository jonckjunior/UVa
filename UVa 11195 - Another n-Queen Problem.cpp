#include <bits/stdc++.h>

using namespace std;

int n,res,OK;
int block[20][20];
vector<string> vs;

void solve(int rw, int ld, int rd, int col){
    //printf("%d %d %d %d\n", rw, ld, rd, col);
    if(rw == OK){
        res++;
        return;
    }
    int pos = OK & (~(rw | ld | rd));
    while(pos){
        int p = pos & -pos;
        pos -= p;
        int lastBit = 0;
        for(int i = 0; i < 15; i++)
            if((1<<i) & p) lastBit = i;
        //printf("lastBit = %d\n", lastBit);
        if(!block[lastBit][col])
            solve(rw|p, (ld|p) << 1, (rd|p) >> 1, col+1);
    }
}

int main(){
    int caso = 0;
    while(cin >> n, n){
        getchar();
        OK = (1 << n) - 1;
        vs.assign(n+5, "");
        for(int i = 0; i < n; i++)
            getline(cin, vs[i]);
        memset(block, 0, sizeof block);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(vs[i][j] == '*')
                    block[i][j] = 1;
        res = 0;
        solve(0,0,0,0);
        printf("Case %d: %d\n",++caso,res);
    }
    return 0;
}
