#include <bits/stdc++.h>
#define INF 1e7
#define MAX_N 30
#define bit(i) (1<<i)
#define UNVISITED -1
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

struct Edge{
    long long int u,v,w;
    Edge(){}
    Edge(long long int a, long long int b,long long int c){u = a;v = b;w = c;}
    bool operator<(const Edge& b) const{return w < b.w;}
};

class UnionFind {
    private: vi p, rank;

    public:
        UnionFind(int N) { rank.assign(N, 0);
        p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
        int x = findSet(i), y = findSet(j);
        /*if (rank[x] > rank[y])  p[y] = x;
        else {                  p[x] = y;
                                if (rank[x] == rank[y]) rank[y]++; }*/
        p[x] = y;
} } };

int main(){
    long long int m,n,x,y,w;
    ios::sync_with_stdio(false);
    while(cin >> m >> n && m+n != 0){
        vector<Edge> E;
        vector<long long int> cycles;
        for(int i = 0; i < n; i++){
            cin >> x >> y >> w;
            E.push_back(Edge(x,y,w));
        }
        UnionFind UF(m);
        sort(E.begin(), E.end());
        for(int i = 0; i < n; i++){
            Edge front = E[i];
            if(!UF.isSameSet(front.u, front.v))
                UF.unionSet(front.u, front.v);
            else
                cycles.push_back(front.w);
        }
        if(cycles.size() == 0) printf("forest\n");
        else{
            //sort(cycles.begin(), cycles.end());
            for(int i = 0; i < cycles.size(); i++){
                if(i == 0) printf("%lld",cycles[i]);
                else       printf(" %lld",cycles[i]);
            }
            printf("\n");
        }
    }
}
