#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i) = 0; (i) < (n); (i)++)
#define MAX_V 105
#define INF 1000001
typedef vector<int> vi;
int res[MAX_V][MAX_V], s=0,t=37, f,mf, n,act;
vi p;

void augment(int v, int minEdge){
    if(v==s){
        f = minEdge;
        return;
    }
    else if(p[v] != -1){
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

void maxflow(){
    mf = 0;
    while(1){
        f = 0;
        vi dist(MAX_V, INF); dist[s] = 0; queue<int> q; q.push(s);
        p.assign(MAX_V, -1);
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(u == t) break;
            for(int v = s; v <= t; v++){
                if(res[u][v] > 0 && dist[v] == INF)
                    dist[v] = dist[u] + 1, q.push(v), p[v] = u;
            }
        }
        augment(t, INF);
        if(f==0) break;
        mf += f;
    }
}

void printAnswer(){
    for(int i = 27; i < t; i++)
                res[i][t] = res[t][i] = 1;
            maxflow();
            if(mf != act) cout << "!" << endl;
            else{
                for(int i = 27; i < t; i++){
                    int flag = 0;
                    for(int j = 1; j < 27; j++){
                        if(res[i][j]){
                            printf("%c",j+'A'-1);
                            flag=1;
                        }
                    }
                    if(!flag) cout << "_";
                }
                cout << endl;
            }
            act = 0;
            memset(res, 0, sizeof res);
}

int main(){
    string s1;
    memset(res, 0, sizeof res);
    while(getline(cin,s1)){
        if(s1.size() == 0){
            printAnswer();
        }
        else{
            int app = s1[0]-'A'+1;
            int numUser = s1[1]-'0';
            act += numUser;
            res[s][app] += numUser;
            res[app][s] += numUser;
            for(int i = 3; i < s1.size()-1; i++){
                int pc = s1[i]-'0'+27;
                res[app][pc] = 1;
            }
        }
    }
    printAnswer();
}
