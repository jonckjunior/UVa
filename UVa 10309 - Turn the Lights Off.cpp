#include <bits/stdc++.h>

using namespace std;
#define bit(i) (1 << (i))
vector<string> vs(15);

int mm[15][15], aux[15][15];

bool valid(int x, int y){
    if(x < 0 || x >= 10 || y < 0 || y >= 10) return false;
    else return true;
}

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void flip(int x, int y){
    aux[x][y] = !aux[x][y];
    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(valid(xx,yy))
            aux[xx][yy] = !aux[xx][yy];
    }
}

int solve(){
    int res = 0;
    for(int i = 1; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(aux[i-1][j] == 1){
                flip(i,j);
                res++;
            }
        }
    }
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            if(aux[i][j]) return -1;
    return res;
}

int main(){
    string caso;
    while(getline(cin, caso), caso != "end"){
        //getchar();
        //string lala;
        //getline(cin,lala);
        for(int i = 0; i < 10; i++)
            getline(cin, vs[i]);
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 10; j++)
                mm[i][j] = (vs[i][j] == 'O');
        int res = -2;

        /*printf("inicial\n");
        for(int j = 0; j < 10; j++){
                for(int k = 0; k < 10; k++)
                    printf("%d ", mm[j][k]);
                cout << endl;
        }*/

        for(int i = 0; i < 1024; i++){

            for(int j = 0; j < 10; j++)
                for(int k = 0; k < 10; k++)
                    aux[j][k] = mm[j][k];
            int bitsOn = 0;
            for(int j = 0; j < 15; j++)
                if(bit(j) & i) {
                    //printf("flipando %d %d\n",j,0);
                    bitsOn++;
                    flip(0,j);
                }
            /*printf("dando solve em : \n");

            for(int j = 0; j < 10; j++){
                for(int k = 0; k < 10; k++)
                    printf("%d ", aux[j][k]);
                cout << endl;
            }*/

            int aux = solve();
            if(aux != -1) {
                if(res == -2) res = 1e9;
                res = min(res, aux+bitsOn);
            }
        }
        // int res = solve();
        if(res == -2) res = -1;
        cout << caso << " " << res << endl;
        //cout << string(10, '\n') << endl;
    }
    return 0;
}
