#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string.h>
#include <bitset>
#include <algorithm>
using namespace std;
#define bit(i) (1<<i)
#define MAX_N 257
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


vector< pair<int,ii> > vt;
int capacity, n, tickets;


int backtrack(int u, int p, int mark){
    if(p > capacity) return -1e8;
    if(u >= tickets) return 0;
    for(int i = 0; i < tickets; i++)
        if(mark&bit(i) && vt[i].second.first <= vt[u].first) p-=vt[i].second.second,mark^=bit(i);
    int esq = backtrack(u+1,p,mark);
    int dir = backtrack(u+1,p+vt[u].second.second,mark|bit(u))+(vt[u].second.first - vt[u].first)*vt[u].second.second;
    return max(esq,dir);
}

int main(){
    int x,y,t;
    while(cin >> capacity >> n >> tickets && capacity + n + tickets != 0){
        vt.clear();
        for(int i = 0; i < tickets; i++){
            scanf("%d %d %d",&x,&y,&t);
            vt.push_back(make_pair(x,ii(y,t)));
        }
        sort(vt.begin(), vt.end());
        cout << backtrack(0,0,0) << endl;
    }

}

