#include <iostream>
#include <cstdio>
#include <vector>
#define UNVISITED -1
#define BLACK 1
#define WHITE 0
using namespace std;

typedef vector<int> vi;
vector<vi> AdjList;
vi color, res, aux;
int v, maxblack;    

bool isValidBlack(int u){
    for(int i = 0; i < AdjList[u].size(); i++)
        if(color[AdjList[u][i]] == BLACK) return false;
    return true;
}

void solve(int u){
    //cout << "---INFINITE---" << endl;
    if(u==v){
        int black=0;
        for(int i = 0; i < color.size(); i++)
            if(color[i] == BLACK) black++;
        if(black >= maxblack){
            maxblack = black;
            res = color;
        }
        return;
    }
    if(isValidBlack(u)){
        color[u] = BLACK;
        solve(u+1);
    }
    color[u] = WHITE;
    solve(u+1);

}

int main() {
    int t,x,y,e;
    cin >> t;
    while(t--){
        cin >> v >> e;
        AdjList.assign(v,vi());
        color.assign(v,UNVISITED);
        for(int i = 0; i < e; i++){
            scanf("%d %d",&x,&y);
            x--;y--;
            AdjList[x].push_back(y);
            AdjList[y].push_back(x);
        }
        maxblack = -1;
        solve(0);
        cout << maxblack << endl;
        bool first = true;
        for(int i = 0; i < res.size(); i++){
            if(res[i] == BLACK && first) printf("%d",i+1), first = false;
            else if(res[i] == BLACK && !first) printf(" %d",i+1);
        }
        cout << endl;
    }
    return 0;
}
