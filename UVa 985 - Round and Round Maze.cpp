#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

struct state{
    vvi tempo;
    state(){tempo.assign(5, vi());}
};

struct nodo{
    int x, y, tempo;
    nodo(int xx, int yy, int tt){x = xx; y = yy;tempo=tt;}
};

int n,m,res;
int delta[] = {UP, RIGHT, DOWN, LEFT};
int dist[505][505][5];

vector< vector<state> > adj;

bool valid(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    else return true;
}

int getPos(char c){
    if(c == 'N') return UP;
    else if(c == 'W') return LEFT;
    else if(c == 'S') return DOWN;
    else return RIGHT;
}

void setState(int x, int y, int op){
    for(int i = 0; i < 4; i++)
        adj[x][y].tempo[i].push_back(delta[(op+i)%4]);
}

int bfs(){
    queue<nodo> q; q.push(nodo(0,0,0));
    memset(dist, 0, sizeof dist);
    dist[0][0][0] = 1;
    while(!q.empty()){
        // printf("here1\n");
        nodo frente = q.front(); q.pop();
        int x = frente.x, y = frente.y, t = frente.tempo%4;
        //printf("%d %d %d\n",x,y,t);
        if(x == n-1 && y == m-1) return dist[x][y][t];
        // printf("here3\n");
        for(int i = 0; i < (int)adj[x][y].tempo[t].size(); i++){
            //printf("here4\n");
            int op = adj[x][y].tempo[t][i];
            int xx = x, yy = y;
            if(op == UP) xx--;
            else if(op == DOWN) xx++;
            else if(op == LEFT) yy--;
            else if(op == RIGHT) yy++;
            if(valid(xx,yy) && dist[xx][yy][(t+1)%4] == 0){
                // printf("here5\n");
                dist[xx][yy][(t+1)%4] = dist[x][y][t] + 1;
                q.push(nodo(xx,yy,t+1));
                // printf("here6\n");
            }
        }
    }
    return -1;
}

int main(){
    while(scanf("%d %d",&n,&m) != EOF){
        adj.assign(n+5, vector<state>(m+5, state()));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(i == n-1 && j == m-1) continue;
                string ss;
                cin >> ss;
                for(int k = 0; k < (int)ss.size(); k++){
                    int pos = getPos(ss[k]);
                    setState(i,j,pos);
                }
                /*for(int k = 0; k < 4; k++){
                    printf("tempo = %d\n",k);
                    for(int l = 0; l < (int)adj[i][j].tempo[k].size(); l++)
                        printf("%d ", adj[i][j].tempo[k][l]);
                    printf("\n");
                }*/
            }
        res = bfs();
        if(res == -1) printf("no path to exit\n");
        else printf("%d\n",res-1);
    }
    return 0;
}
