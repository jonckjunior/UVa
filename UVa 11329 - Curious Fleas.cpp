#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define INF 0x3f3f3f3f

int dist[(1 << 26) + 5];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int dices[][6]{
    {1,2,3,0,4,5},
  {3,0,1,2,4,5},
  {4,1,5,3,2,0},
  {5,1,4,3,0,2}};

int bit(int b){return (1 << b);}
int bitmask(int x, int y){return (x << y);}

int mask(int tab, int x, int y, int dice){
    return (tab | bitmask(x,16) | bitmask(y,18) | bitmask(dice,20));
}

bool valid(int x, int y){
    if(x < 0 || x >= 4 || y < 0 || y >= 4) return false;
    else return true;
}

struct node{
    int tab,x,y,dice;
    node(int tt, int xx, int yy, int dd){tab = tt; x = xx; y = yy; dice = dd;}
};

int roll(int dice, int pos){
    int r = 0;
    for (int i = 0; i < 6; i++) {
        if (dice & bit(dices[pos][i])) {
          r = r | bit(i);
        }
    }
    return r;
}

void solve(){
    queue<node> q;
    memset(dist, -1, sizeof dist);
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++){
            q.push(node(0,i,j,(1 << 6) - 1));
            int aux = mask(0,i,j,(1 << 6) - 1);
            dist[aux] = 0;
        }
    int k = 0;
    while(!q.empty()){
        node topo = q.front(); q.pop();
        int tab = topo.tab, x = topo.x, y = topo.y, dice = topo.dice;
        int mascara = mask(tab, x, y, dice);
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i], yy = y + dy[i];
            if(valid(xx,yy)){
                int tt = tab, dd = dice;

                int lowDice = dd & 1;
                int pos = x*4+y;
                int lowTab = (tt >> pos)&1;

                if(lowDice != lowTab){
                    dd = dd ^ 1;
                    tt = tt ^ (1 << pos);

                }

                dd = roll(dd, i);

                int next = mask(tt, xx, yy, dd);
                if(dist[next] == -1){
                    dist[next] = dist[mascara] + 1;
                    q.push(node(tt, xx, yy, dd));
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    solve();
    while(t--){
        int tabela = 0;
        int x,y;
        for(int i = 0; i < 4; i++){
            string ss; cin >> ss;
            for(int j = 0; j < 4; j++){
                if(ss[j] == 'D')
                    x = i, y = j;
                else if(ss[j] == 'X')
                    tabela |= bit(i*4+j);
            }
        }
        int res = mask(tabela, x, y, 0);
        res = dist[res];
        if(res == -1) cout << "impossible" << endl;
        else cout << res << endl;
    }
    
    return 0;
}
