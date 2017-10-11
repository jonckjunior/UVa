#include <bits/stdc++.h>
using namespace std;

int n,m;

int xPonto[5], yPonto[5], distPonto[5];

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int vis[10][10], valorFinal, res;

bool valid(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    else return true;
}

bool bfs(){
    queue<ii> q; q.push(ii(n-1,1));
    int mark[10][10] = {0};
    mark[n-1][1] = 1;
    while(!q.empty()){
        ii frente = q.front(); q.pop();
        int x = frente.first, y = frente.second;
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i], yy = y + dy[i];
            if(valid(xx,yy) && !mark[xx][yy] && !vis[xx][yy]){
                mark[xx][yy] = 1;
                q.push(ii(xx,yy));
            }
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!mark[i][j] && !vis[i][j]) return false;
    return true;
}

bool check2(int x, int y){
    static int v[9], i, j;
    v[0] = x-1 < 0 || y-1 < 0 || vis[x-1][y-1];
    v[1] = x-1 < 0 || vis[x-1][y];
    v[2] = x-1 < 0 || y+1 >= m || vis[x-1][y+1];
    v[3] = y+1 >= m || vis[x][y+1];
    v[4] = x+1 >= n || y+1 >= m || vis[x+1][y+1];
    v[5] = x+1 >= n || vis[x+1][y];
    v[6] = x+1 >= n || y-1 < 0 || vis[x+1][y-1];
    v[7] = y-1 < 0 || vis[x][y-1];
    v[8] = v[0];
    for(i = 0, j = 0; i < 8; i++)
        if(v[i] != v[i+1])
            j++;
    return j >= 4;
}

bool check(int x, int y, int d){
    for(int i = 0; i < 3; i++)
        if(d == distPonto[i] && (x != xPonto[i] || y != yPonto[i]))
            return false;
    for(int i = 0; i < 3; i++)
        if(d < distPonto[i]){
            if(distPonto[i]-d < abs(xPonto[i]-x) + abs(yPonto[i]-y))
                return false;
            break;
        }
    if(check2(x,y)) return false;
    // if(!bfs()) return false;
    return true;
}

void solve(int x, int y, int d){
    if(x == n-1 && y == 1){
        if(d == valorFinal) res++;
        return;
    }
    if(!check(x,y,d)) return;
    vis[x][y] = 1;

    for(int i = 0; i < 4; i++){
        int xx = x + dx[i], yy = y + dy[i];
        if(valid(xx,yy) && !vis[xx][yy]){
            solve(xx,yy,d+1);
        }
    }

    vis[x][y] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    int caso = 0;
    while(cin >> n >> m, n + m != 0){
        memset(vis, 0, sizeof vis);
        res = 0;
        valorFinal = n*m;
        for(int i = 0; i < 3; i++){
            cin >> xPonto[i] >> yPonto[i];
            xPonto[i] = n - xPonto[i] - 1;
            distPonto[i] = floor((i+1) * n * m / 4.0);
        }
        solve(n-1, 0, 1);
        cout << "Case " << ++caso << ": " << res << endl;
    }
    return 0;
}
