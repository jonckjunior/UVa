#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int const maxv = 55;
int n, degree[maxv];
list<int> cyc;
vector<vii> adj;

void EulerTour(list<int>:: iterator i, int u){
    for(int j = 0; j < adj[u].size(); j++){
        ii &v = adj[u][j];
        if(v.second){
            v.second = 0;
            for(int k = 0; k < adj[v.first].size(); k++){
                ii &uu = adj[v.first][k];
                if(uu.first == u && uu.second){
                    uu.second = 0;
                    break;
                }
            }
            EulerTour(cyc.insert(i,u),v.first);
        }
    }
}

int main(){
    int t,x,y,caso=0;
    cin >> t;
    while(t--){
        cin >> n;
        adj.assign(maxv, vii());
        cyc.clear();
        memset(degree, 0, sizeof degree);
        int first_color = -1;
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            x--;y--;
            if(first_color == -1) first_color = x;
            degree[x]++;
            degree[y]++;
            adj[x].push_back(ii(y,1));
            adj[y].push_back(ii(x,1));
        }
        int possible = 1;
        for(int i = 0; i < maxv && possible; i++)
            if(degree[i]&1) possible = 0;

        printf("Case #%d\n",++caso);
        if(possible){
            EulerTour(cyc.begin(), first_color);
            list<int>::iterator it = cyc.begin();
            first_color = *it;
            for(it = cyc.begin() ; it != cyc.end(); it++){
                int at = *it;
                it++;
                if(it != cyc.end()){
                    int v = *it;
                    printf("%d %d\n",at+1,v+1);
                    --it;
                }
                else{
                    --it;
                    printf("%d %d\n",*it+1, first_color+1);
                }
            }
        }
        else
            cout << "some beads may be lost" << endl;
        if(t) cout << endl;
    }
}
