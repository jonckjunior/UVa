#include <bits/stdc++.h>
#define INF 1e9
#define bit(i) (1<<i)
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int,double> id;
typedef vector<id> vid;

int n;
double g[10][10], bestsum, mini;
vi ans,v, visit, seq, min_seq;
vii p;

double dist(const ii &a, const ii& b){
    return sqrt( pow((a.first - b.first),2) + pow((a.second - b.second),2) );
}

void dfs(int u, double sum, int mark){
    if(v.size() == n){
        if(sum < bestsum){
            for(int i = 0 ; i < n; i++)
                ans[i] = v[i];
            bestsum = sum;
        }
        return;
    }
    for(int i = 0; i < n; i++)
        if(!(bit(i)&mark)){
            v.push_back(i);
            dfs(i,sum+g[u][i],mark|bit(i));
            v.pop_back();
        }
}

int main(){
    int x, y, caso = 0;
    while(cin >> n && n){
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            p.push_back(ii(x,y));
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                g[i][j] = dist(p[i],p[j]);
        bestsum = INF;
        ans.assign(n,0);
        for(int i = 0; i < n; i++){
            v.push_back(i);
            dfs(i,0,bit(i));
            v.pop_back();
        }
        printf("**********************************************************\n");
        printf("Network #%d\n",++caso );
        for(int i = n-1; i >= 1; i--){
            int u = ans[i], z = ans[i-1];
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",p[u].first,p[u].second,p[z].first, p[z].second, g[z][u]+16);
        }
        printf("Number of feet of cable required is %.2lf.\n",bestsum+16*(n-1));
        p.clear();
    }
}
