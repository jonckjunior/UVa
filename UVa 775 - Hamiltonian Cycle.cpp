#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string.h>
#include <bitset>
using namespace std;
#define bit(i) (1<<i)
#define MAX_N 257
typedef pair<int,int> ii;

int n;
int g[MAX_N][MAX_N];
vector< int > nodes;
bool found;
bitset<MAX_N> mark;
bitset<MAX_N> final;
void backtrack(int u){
    //printf("---INFINITE---\n");
    if(found) return;
    if(u == 0 && mark == final){
        //printf("---FOUND---\n");
        found=true;
        for(int i = 0; i < nodes.size()-1; i++)
            printf("%d ",nodes[i]+1);
        printf("%d\n",nodes[nodes.size()-1]+1);
        return;
    }
    for(int i = 0; i < n; i++){

        if( g[u][i] && (mark.test(i) == 0 || (i==0 && mark == final)) ){
            nodes.push_back(i);
            mark.set(i,1);
            backtrack(i);
            mark.set(i,0);
            nodes.pop_back();
        }
    }
}

int main(){
    int x,y;
    char c;
    string s;
    while(scanf("%d\n",&n) != EOF){
        memset(g,0,sizeof g);
        nodes.clear();
        while(getline(cin,s) && s.size() > 1){
            sscanf(s.c_str(),"%d %d",&x,&y);
            x--;y--;
            // /printf("g[%d][%d] = 1\n",x,y);
            g[x][y] = 1;
            g[y][x] = 1;
        }
        found = false;
        //printf("---DEBUG---\n");
        nodes.push_back(0);
        mark.reset();
        final.reset(); 
        mark.set(0,1);
        for(int i = 0; i < n; i++)
            final[i] = 1;
        backtrack(0);
        if(!found) cout << n << endl;
    }
}

