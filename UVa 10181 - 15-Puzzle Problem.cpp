#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi finalera;

int limite, nextLimite;
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
char ans[] = "RULD";

map<int,int> pai;

int heuristica(const vvi &tab){
    int res = 0;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++){
            if(tab[i][j] == 15) continue;
            int x = tab[i][j]/4, y = tab[i][j]%4;
            res += abs(x-i) + abs(y-j);
        }
    return res;
}


bool valid(int x, int y){
    if(x < 0 || x >= 4 || y < 0 || y >= 4) return false;
    else return true;
}

void output(int d){
    if(d == 0)
        return;
    output(d-1);
    printf("%c", ans[pai[d]]);
}

bool dfs(int g, int h, vvi& tab, int x, int y, map<vvi,int> &vis){
    
    if(g+h > limite){
        nextLimite = min(nextLimite, g + h);
        return false;
    }
    if(tab == finalera){
        return true;
    }
    if(vis.count(tab) && vis[tab] <= g){
        return false;
    }
    vis[tab] = g;

    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        
        if(valid(xx,yy)){

            swap(tab[x][y], tab[xx][yy]);

            int novoH = heuristica(tab);
            pai[g+1] = i;
            if(dfs(g+1, novoH, tab, xx, yy, vis)){
                return true;
            }

            swap(tab[x][y], tab[xx][yy]);
        }
    }
    return false;
}

int IDA_Star(vvi init, int x, int y){
    limite = heuristica(init);
    // printf("heuristica inical = %d\n",limite);
    while(true){
        nextLimite = 1e9;
        map<vvi, int> vis;
        pai.clear();
        if(dfs(0, heuristica(init), init, x, y, vis)){
            // printf("deu boa\n");
            return limite;
        }
        if(nextLimite == 1e9)
            return -1;
        limite = nextLimite;
        // printf("novo limite = %d\n", limite);
        if(limite > 45)
            return -1;
    }
}

int main() {
    int t;
    cin >> t;
    finalera.assign(4, vi(4, 0));
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            finalera[i][j] = i*4+j;

    while(t--){
        int x,y;

        vvi init(4, vi(4,0));

        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++){
                scanf("%d",&init[i][j]);
                if(init[i][j] == 0){
                    x = i, y = j;
                    init[i][j] = 15;
                }
                else
                    init[i][j]--;
            }
        
        int vetorzera[16];
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                vetorzera[i*4+j] = init[i][j];
        int aux = 0;
        for(int i = 0; i < 16; i++)
            for(int j = 0; j < i; j++)
                if(vetorzera[i] != 15 && vetorzera[j] != 15 && vetorzera[j] > vetorzera[i])
                    aux++;
        aux += x;

        if(aux % 2 == 0)
            printf("This puzzle is not solvable.\n");
        else{
            int res = IDA_Star(init, x, y);
            if(res == -1)
                printf("This puzzle is not solvable.\n");
            else
                output(res), printf("\n");
        }
    }
    return 0;
}
